'******************************************************************************
'Microsoft Confidential. © 2002-2003 Microsoft Corporation. All rights reserved.
'
' This file may contain preliminary information or inaccuracies, 
' and may not correctly represent any associated Microsoft 
' Product as commercially released. All Materials are provided entirely 
' “AS IS.” To the extent permitted by law, MICROSOFT MAKES NO 
' WARRANTY OF ANY KIND, DISCLAIMS ALL EXPRESS, IMPLIED AND STATUTORY 
' WARRANTIES, AND ASSUMES NO LIABILITY TO YOU FOR ANY DAMAGES OF 
' ANY TYPE IN CONNECTION WITH THESE MATERIALS OR ANY INTELLECTUAL PROPERTY IN THEM. 
'******************************************************************************

Option Explicit

Wscript.Echo "" 
Wscript.Echo "REGISTER_APP.VBS version 1.6 for Windows Server 2008"
Wscript.Echo "Copyright (C) Microsoft Corporation 2002-2003. All rights reserved."
Wscript.Echo "" 


'******************************************************************************
' Parse command line arguments
'******************************************************************************
Dim Args
Set Args = Wscript.Arguments
If Args.Count < 1 Then 
	PrintsUsage
End If

Dim ProviderName, ProviderDLL, ProviderDescription
If Args.Item(0) = "-register" Then 
	If Args.Count <> 4 Then PrintsUsage

	ProviderName = Args.Item(1)
	ProviderDLL = Args.Item(2)
	ProviderDescription = Args.Item(3)

	UninstallProvider
	InstallProvider
	Wscript.Quit 0
End If 

If Args.Item(0) = "-unregister" Then 
	If Not Args.Count = 2 Then PrintsUsage
	ProviderName = Args.Item(1)
	UninstallProvider
	Wscript.Quit 0
End If

' Wrong options?
PrintsUsage

Wscript.Quit 0

'******************************************************************************
' Prints the usage
'******************************************************************************
Sub PrintsUsage

	Wscript.Echo "Usage:" 
	Wscript.Echo "" 
	Wscript.Echo " 1) Registering a VSS/VDS Provider as a COM+ application:" 
	Wscript.Echo "      CScript.exe " & Wscript.ScriptName & " -register <Provider_Name> <Provider.DLL>  <Provider_Description>" 
	Wscript.Echo "" 
	Wscript.Echo " 2) Unregistering a COM+ application associated with a VSS/VDS provider:" 
	Wscript.Echo "      CScript.exe " & Wscript.ScriptName & " -unregister <Provider_Name>" 
	Wscript.Echo "" 
	Wscript.Quit 1

End Sub


'******************************************************************************
' Installs the Provider
'******************************************************************************
Sub InstallProvider
	On Error Resume Next

	Wscript.Echo "Creating a new COM+ application:" 

	Wscript.Echo "- Creating the catalog object "
	Dim cat
	Set cat = CreateObject("COMAdmin.COMAdminCatalog") 	
	CheckError 101

	wscript.echo "- Get the Applications collection"
	Dim collApps
	Set collApps = cat.GetCollection("Applications")
	CheckCollectionError 102, cat

	Wscript.Echo "- Populate..." 
	collApps.Populate 
	CheckCollectionError 103, collApps

	Wscript.Echo "- Add new application object" 
	Dim app
	Set app = collApps.Add 
	CheckCollectionError 104, collApps

	Wscript.Echo "- Set app name = " & ProviderName & " "
	app.Value("Name") = ProviderName
	CheckObjectError 105, collApps, app

	Wscript.Echo "- Set app description = " & ProviderDescription & " "
	app.Value("Description") = ProviderDescription 
	CheckObjectError 106, collApps, app

	' Only roles added below are allowed to call in.
	Wscript.Echo "- Set app access check = true "
	app.Value("ApplicationAccessChecksEnabled") = 1   
	CheckObjectError 107, collApps, app

	' Encrypting communication
	Wscript.Echo "- Set encrypted COM communication = true "
	app.Value("Authentication") = 6	                  
	CheckObjectError 108, collApps, app

	' Secure references
	Wscript.Echo "- Set secure references = true "
	app.Value("AuthenticationCapability") = 2         
	CheckObjectError 109, collApps, app

	' Do not allow impersonation
	Wscript.Echo "- Set impersonation = false "
	app.Value("ImpersonationLevel") = 2               
	CheckObjectError 110, collApps, app

	Wscript.Echo "- Save changes..."
	collApps.SaveChanges
	CheckCollectionError 111, collApps

	wscript.echo "- Create Windows service running as Local System"
	cat.CreateServiceForApplication ProviderName, ProviderName , "SERVICE_AUTO_START", "SERVICE_ERROR_NORMAL", "", ".\localsystem", "", 0
	CheckCollectionError 112, cat

	wscript.echo "- Add the DLL component"
	cat.InstallComponent ProviderName, ProviderDLL , "", ""
        CheckCollectionError 113, cat

	'
	' Add the new role for the Local SYSTEM account
	'

	wscript.echo "Secure the COM+ application:"
	wscript.echo "- Get roles collection"
	Dim collRoles
	Set collRoles = collApps.GetCollection("Roles", app.Key)
	CheckCollectionError 120, cat

	wscript.echo "- Populate..."
	collRoles.Populate
	CheckCollectionError 121, collRoles

	wscript.echo "- Add new role"
	Dim role
	Set role = collRoles.Add
	CheckCollectionError 122, collRoles

	wscript.echo "- Set name = Administrators "
	role.Value("Name") = "Administrators"
	CheckObjectError 123, collRoles, role

	wscript.echo "- Set description = Administrators group "
	role.Value("Description") = "Administrators group"
	CheckObjectError 124, collRoles, role

	wscript.echo "- Save changes ..."
	collRoles.SaveChanges
	CheckCollectionError 125, collRoles
	
	'
	' Add users into role
	'

	wscript.echo "Granting user permissions:"
	Dim collUsersInRole
	Set collUsersInRole = collRoles.GetCollection("UsersInRole", role.Key)
	CheckCollectionError 130, collRoles

	wscript.echo "- Populate..."
	collUsersInRole.Populate
	CheckCollectionError 131, collUsersInRole

	wscript.echo "- Add new user"
	Dim user
	Set user = collUsersInRole.Add
	CheckCollectionError 132, collUsersInRole

	wscript.echo "- Searching for the Administrators account using WMI..."

	' Get the Administrators account domain and name
	Dim strQuery
	strQuery = "select * from Win32_Account where SID='S-1-5-32-544' and localAccount=TRUE"
	Dim objSet
	set objSet = GetObject("winmgmts:").ExecQuery(strQuery)
	CheckError 133

	Dim obj, Account
	for each obj in objSet
	    set Account = obj
		exit for
	next

	wscript.echo "- Set user name = .\" & Account.Name & " "
	user.Value("User") = ".\" & Account.Name
	CheckObjectError 140, collUsersInRole, user

	wscript.echo "- Add new user"
	Set user = collUsersInRole.Add
	CheckCollectionError 141, collUsersInRole

	wscript.echo "- Set user name = Local SYSTEM "
	user.Value("User") = "NT AUTHORITY\SYSTEM"
	CheckObjectError 142, collUsersInRole, user

	wscript.echo "- Save changes..."
	collUsersInRole.SaveChanges
	CheckCollectionError 143, collUsersInRole
	
	Set app      = Nothing
	Set cat      = Nothing
	Set role     = Nothing
	Set user     = Nothing

	Set collApps = Nothing
	Set collRoles = Nothing
	Set collUsersInRole	= Nothing

	set objSet   = Nothing
	set obj      = Nothing

	Wscript.Echo "Done." 

	On Error GoTo 0
End Sub


'******************************************************************************
' Uninstalls the Provider
'******************************************************************************
Sub UninstallProvider
	On Error Resume Next

	Wscript.Echo "Unregistering the existing application..." 

	wscript.echo "- Create the catalog object"
	Dim cat
	Set cat = CreateObject("COMAdmin.COMAdminCatalog")
	CheckError 201
	
	wscript.echo "- Get the Applications collection"
	Dim collApps
	Set collApps = cat.GetCollection("Applications")
	CheckCollectionError 202, cat

	wscript.echo "- Populate..."
	collApps.Populate
	CheckCollectionError 203, collApps
	
	wscript.echo "- Search for " & ProviderName & " application..."
	Dim numApps
	numApps = collApps.Count
	Dim i
	For i = numApps - 1 To 0 Step -1
	    If collApps.Item(i).Value("Name") = ProviderName Then
	        collApps.Remove(i)
		CheckCollectionError 204, collApps
                WScript.echo "- Application " & ProviderName & " removed!"
	    End If
	Next
	
	wscript.echo "- Saving changes..."
	collApps.SaveChanges
	CheckCollectionError 205, collApps

	Set collApps = Nothing
	Set cat      = Nothing

	Wscript.Echo "Done." 

	On Error GoTo 0
End Sub



'******************************************************************************
' Sub CheckError
'******************************************************************************
Sub CheckError(exitCode)
    If Err = 0 Then Exit Sub
    DumpVBScriptError exitCode

    Wscript.Quit exitCode
End Sub


'******************************************************************************
' Sub CheckCollectionError
'******************************************************************************
Sub CheckCollectionError(exitCode, coll)
    If Err = 0 Then Exit Sub
    DumpVBScriptError exitCode

    DumpComPlusError(coll.GetCollection("ErrorInfo"))

    Wscript.Quit exitCode
End Sub


'******************************************************************************
' Sub CheckObjectError
'******************************************************************************
Sub CheckObjectError(exitCode, coll, object)
    If Err = 0 Then Exit Sub
    DumpVBScriptError exitCode

    ' DumpComPlusError(coll.GetCollection("ErrorInfo", object.Key))
    DumpComPlusError(coll.GetCollection("ErrorInfo"))

    Wscript.Quit exitCode
End Sub



'******************************************************************************
' Sub DumpVBScriptError
'******************************************************************************
Sub DumpVBScriptError(exitCode)
    WScript.Echo vbNewLine & "ERROR:"
    WScript.Echo "- Error code: " & Err & " [0x" & Hex(Err) & "]"
    WScript.Echo "- Exit code: " & exitCode
    WScript.Echo "- Description: " & Err.Description
    WScript.Echo "- Source: " & Err.Source
    WScript.Echo "- Help file: " & Err.Helpfile
    WScript.Echo "- Help context: " & Err.HelpContext
End Sub


'******************************************************************************
' Sub DumpComPlusError
'******************************************************************************
Sub DumpComPlusError(errors)
    errors.Populate
    WScript.Echo "- COM+ Errors detected: (" & errors.Count & ")"

    Dim error
    Dim I
    For I = 0 to errors.Count - 1
	Set error = errors.Item(I)
        WScript.Echo "   * (COM+ ERROR " & I & ") on " & error.Value("Name")
        WScript.Echo "       ErrorCode: " & error.Value("ErrorCode") & " [0x" & Hex(error.Value("ErrorCode")) & "]"
        WScript.Echo "       MajorRef: " & error.Value("MajorRef")
        WScript.Echo "       MinorRef: " & error.Value("MinorRef")
    Next
End Sub


'' SIG '' Begin signature block
'' SIG '' MIIh9AYJKoZIhvcNAQcCoIIh5TCCIeECAQExDzANBglg
'' SIG '' hkgBZQMEAgEFADB3BgorBgEEAYI3AgEEoGkwZzAyBgor
'' SIG '' BgEEAYI3AgEeMCQCAQEEEE7wKRaZJ7VNj+Ws4Q8X66sC
'' SIG '' AQACAQACAQACAQACAQAwMTANBglghkgBZQMEAgEFAAQg
'' SIG '' t2OGjVuwrDi7m9eD1oGHZt1e8mT97G6PYHdAzoXpmRWg
'' SIG '' gguBMIIFCTCCA/GgAwIBAgITMwAAA4Pq27vZbyG4+gAA
'' SIG '' AAADgzANBgkqhkiG9w0BAQsFADB+MQswCQYDVQQGEwJV
'' SIG '' UzETMBEGA1UECBMKV2FzaGluZ3RvbjEQMA4GA1UEBxMH
'' SIG '' UmVkbW9uZDEeMBwGA1UEChMVTWljcm9zb2Z0IENvcnBv
'' SIG '' cmF0aW9uMSgwJgYDVQQDEx9NaWNyb3NvZnQgQ29kZSBT
'' SIG '' aWduaW5nIFBDQSAyMDEwMB4XDTIwMDkyNDE5MTAzNVoX
'' SIG '' DTIxMDkyMzE5MTAzNVowfzELMAkGA1UEBhMCVVMxEzAR
'' SIG '' BgNVBAgTCldhc2hpbmd0b24xEDAOBgNVBAcTB1JlZG1v
'' SIG '' bmQxHjAcBgNVBAoTFU1pY3Jvc29mdCBDb3Jwb3JhdGlv
'' SIG '' bjEpMCcGA1UEAxMgTWljcm9zb2Z0IFdpbmRvd3MgS2l0
'' SIG '' cyBQdWJsaXNoZXIwggEiMA0GCSqGSIb3DQEBAQUAA4IB
'' SIG '' DwAwggEKAoIBAQCnt52Kmu4L6Ba3yRL/0obWfohcrE/X
'' SIG '' yxFhdCkbiMbB55kRKDvAu37z1cSAonm45shuXzH5EWIB
'' SIG '' w06wzKPt0RHFt9yp5JNQOgglKttQ+JNOjhCA5Rr6rKwP
'' SIG '' PjPstu/8doUJ5uvSZR6tqYee/f5krppjMclmkNC2Dgrw
'' SIG '' 9yOmYt5BUvCUNAto/EaX5UhodlIfdF9aNZZ5mY0+dvjq
'' SIG '' P99wtsRirRmkPLKyAclZHV10w0qhAcANGPLjNurpjiBI
'' SIG '' T5oQWOYOAGX8A91Bovzwf1Qh3HsYSPE6YdIprFLodldJ
'' SIG '' TawSwJSBWRWXmFjtQg0zNP8YGOKFt0CdwappX4L/eIA4
'' SIG '' ELIRAgMBAAGjggF9MIIBeTAfBgNVHSUEGDAWBgorBgEE
'' SIG '' AYI3CgMUBggrBgEFBQcDAzAdBgNVHQ4EFgQUeEXr3DrQ
'' SIG '' 1r71bRhURXpiKYw85w4wVAYDVR0RBE0wS6RJMEcxLTAr
'' SIG '' BgNVBAsTJE1pY3Jvc29mdCBJcmVsYW5kIE9wZXJhdGlv
'' SIG '' bnMgTGltaXRlZDEWMBQGA1UEBRMNMjI5OTAzKzQ2MTIx
'' SIG '' NDAfBgNVHSMEGDAWgBTm/F97uyIAWORyTrX0IXQjMubv
'' SIG '' rDBWBgNVHR8ETzBNMEugSaBHhkVodHRwOi8vY3JsLm1p
'' SIG '' Y3Jvc29mdC5jb20vcGtpL2NybC9wcm9kdWN0cy9NaWND
'' SIG '' b2RTaWdQQ0FfMjAxMC0wNy0wNi5jcmwwWgYIKwYBBQUH
'' SIG '' AQEETjBMMEoGCCsGAQUFBzAChj5odHRwOi8vd3d3Lm1p
'' SIG '' Y3Jvc29mdC5jb20vcGtpL2NlcnRzL01pY0NvZFNpZ1BD
'' SIG '' QV8yMDEwLTA3LTA2LmNydDAMBgNVHRMBAf8EAjAAMA0G
'' SIG '' CSqGSIb3DQEBCwUAA4IBAQC7A8TJmY/vbWihRJK+FlTv
'' SIG '' R+kHW/TbpVlSyuTw8/V+YfbD7JmqYLs0xLqSIq5qvDst
'' SIG '' 24lUOfVI2bBLBgWE/jsMZQ9QBgmEiVuw2TwgGbdyXHN0
'' SIG '' rggJC8zzZMfqEtyho+caqFMzLIELfAEVWd3kIAWYVNzm
'' SIG '' rD1rpLs3HwnIivyR9mwZyBZfT0k4lrLUUgfERjIeQcAA
'' SIG '' IzoKS11WsIE1s6UuCKSw2Fs3XnybcnugQrOWDGk4CYUA
'' SIG '' B9b1A6ShHUNybwA88859RdDY0am0aaytgAtlGEyCn/Cf
'' SIG '' MmpAjaLtCTYQNw7lHu63HHiMIuJ9pVvUc/0E1rczi3oU
'' SIG '' h+pM7d88sDdZMIIGcDCCBFigAwIBAgIKYQxSTAAAAAAA
'' SIG '' AzANBgkqhkiG9w0BAQsFADCBiDELMAkGA1UEBhMCVVMx
'' SIG '' EzARBgNVBAgTCldhc2hpbmd0b24xEDAOBgNVBAcTB1Jl
'' SIG '' ZG1vbmQxHjAcBgNVBAoTFU1pY3Jvc29mdCBDb3Jwb3Jh
'' SIG '' dGlvbjEyMDAGA1UEAxMpTWljcm9zb2Z0IFJvb3QgQ2Vy
'' SIG '' dGlmaWNhdGUgQXV0aG9yaXR5IDIwMTAwHhcNMTAwNzA2
'' SIG '' MjA0MDE3WhcNMjUwNzA2MjA1MDE3WjB+MQswCQYDVQQG
'' SIG '' EwJVUzETMBEGA1UECBMKV2FzaGluZ3RvbjEQMA4GA1UE
'' SIG '' BxMHUmVkbW9uZDEeMBwGA1UEChMVTWljcm9zb2Z0IENv
'' SIG '' cnBvcmF0aW9uMSgwJgYDVQQDEx9NaWNyb3NvZnQgQ29k
'' SIG '' ZSBTaWduaW5nIFBDQSAyMDEwMIIBIjANBgkqhkiG9w0B
'' SIG '' AQEFAAOCAQ8AMIIBCgKCAQEA6Q5kUHlntcTj/QkATJ6U
'' SIG '' rPdWaOpE2M/FWE+ppXZ8bUW60zmStKQe+fllguQX0o/9
'' SIG '' RJwI6GWTzixVhL99COMuK6hBKxi3oktuSUxrFQfe0dLC
'' SIG '' iR5xlM21f0u0rwjYzIjWaxeUOpPOJj/s5v40mFfVHV1J
'' SIG '' 9rIqLtWFu1k/+JC0K4N0yiuzO0bj8EZJwRdmVMkcvR3E
'' SIG '' VWJXcvhnuSUgNN5dpqWVXqsogM3Vsp7lA7Vj07IUyMHI
'' SIG '' iiYKWX8H7P8O7YASNUwSpr5SW/Wm2uCLC0h31oVH1RC5
'' SIG '' xuiq7otqLQVcYMa0KlucIxxfReMaFB5vN8sZM4BqiU2j
'' SIG '' amZjeJPVMM+VHwIDAQABo4IB4zCCAd8wEAYJKwYBBAGC
'' SIG '' NxUBBAMCAQAwHQYDVR0OBBYEFOb8X3u7IgBY5HJOtfQh
'' SIG '' dCMy5u+sMBkGCSsGAQQBgjcUAgQMHgoAUwB1AGIAQwBB
'' SIG '' MAsGA1UdDwQEAwIBhjAPBgNVHRMBAf8EBTADAQH/MB8G
'' SIG '' A1UdIwQYMBaAFNX2VsuP6KJcYmjRPZSQW9fOmhjEMFYG
'' SIG '' A1UdHwRPME0wS6BJoEeGRWh0dHA6Ly9jcmwubWljcm9z
'' SIG '' b2Z0LmNvbS9wa2kvY3JsL3Byb2R1Y3RzL01pY1Jvb0Nl
'' SIG '' ckF1dF8yMDEwLTA2LTIzLmNybDBaBggrBgEFBQcBAQRO
'' SIG '' MEwwSgYIKwYBBQUHMAKGPmh0dHA6Ly93d3cubWljcm9z
'' SIG '' b2Z0LmNvbS9wa2kvY2VydHMvTWljUm9vQ2VyQXV0XzIw
'' SIG '' MTAtMDYtMjMuY3J0MIGdBgNVHSAEgZUwgZIwgY8GCSsG
'' SIG '' AQQBgjcuAzCBgTA9BggrBgEFBQcCARYxaHR0cDovL3d3
'' SIG '' dy5taWNyb3NvZnQuY29tL1BLSS9kb2NzL0NQUy9kZWZh
'' SIG '' dWx0Lmh0bTBABggrBgEFBQcCAjA0HjIgHQBMAGUAZwBh
'' SIG '' AGwAXwBQAG8AbABpAGMAeQBfAFMAdABhAHQAZQBtAGUA
'' SIG '' bgB0AC4gHTANBgkqhkiG9w0BAQsFAAOCAgEAGnTvV08p
'' SIG '' e8QWhXi4UNMi/AmdrIKX+DT/KiyXlRLl5L/Pv5PI4zSp
'' SIG '' 24G43B4AvtI1b6/lf3mVd+UC1PHr2M1OHhthosJaIxrw
'' SIG '' jKhiUUVnCOM/PB6T+DCFF8g5QKbXDrMhKeWloWmMIpPM
'' SIG '' dJjnoUdD8lOswA8waX/+0iUgbW9h098H1dlyACxphnY9
'' SIG '' UdumOUjJN2FtB91TGcun1mHCv+KDqw/ga5uV1n0oUbCJ
'' SIG '' SlGkmmzItx9KGg5pqdfcwX7RSXCqtq27ckdjF/qm1qKm
'' SIG '' huyoEESbY7ayaYkGx0aGehg/6MUdIdV7+QIjLcVBy78d
'' SIG '' TMgW77Gcf/wiS0mKbhXjpn92W9FTeZGFndXS2z1zNfM8
'' SIG '' rlSyUkdqwKoTldKOEdqZZ14yjPs3hdHcdYWch8ZaV4XC
'' SIG '' v90Nj4ybLeu07s8n07VeafqkFgQBpyRnc89NT7beBVaX
'' SIG '' evfpUk30dwVPhcbYC/GO7UIJ0Q124yNWeCImNr7KsYxu
'' SIG '' qh3khdpHM2KPpMmRM19xHkCvmGXJIuhCISWKHC1g2TeJ
'' SIG '' QYkqFg/XYTyUaGBS79ZHmaCAQO4VgXc+nOBTGBpQHTiV
'' SIG '' mx5mMxMnORd4hzbOTsNfsvU9R1O24OXbC2E9KteSLM43
'' SIG '' Wj5AQjGkHxAIwlacvyRdUQKdannSF9PawZSOB3slcUSr
'' SIG '' Bmrm1MbfI5qWdcUxghXLMIIVxwIBATCBlTB+MQswCQYD
'' SIG '' VQQGEwJVUzETMBEGA1UECBMKV2FzaGluZ3RvbjEQMA4G
'' SIG '' A1UEBxMHUmVkbW9uZDEeMBwGA1UEChMVTWljcm9zb2Z0
'' SIG '' IENvcnBvcmF0aW9uMSgwJgYDVQQDEx9NaWNyb3NvZnQg
'' SIG '' Q29kZSBTaWduaW5nIFBDQSAyMDEwAhMzAAADg+rbu9lv
'' SIG '' Ibj6AAAAAAODMA0GCWCGSAFlAwQCAQUAoIIBBDAZBgkq
'' SIG '' hkiG9w0BCQMxDAYKKwYBBAGCNwIBBDAcBgorBgEEAYI3
'' SIG '' AgELMQ4wDAYKKwYBBAGCNwIBFTAvBgkqhkiG9w0BCQQx
'' SIG '' IgQgorqISAsetE22SO7QBE0kVhcpYE9Wme7Kh+uQRwMU
'' SIG '' I5IwPAYKKwYBBAGCNwoDHDEuDCwyNXhleUNEMHh6WVA3
'' SIG '' em1hTXBiR3d2TTIvYWFSb0hPTGo3OHRXdVZQYzN3PTBa
'' SIG '' BgorBgEEAYI3AgEMMUwwSqAkgCIATQBpAGMAcgBvAHMA
'' SIG '' bwBmAHQAIABXAGkAbgBkAG8AdwBzoSKAIGh0dHA6Ly93
'' SIG '' d3cubWljcm9zb2Z0LmNvbS93aW5kb3dzMA0GCSqGSIb3
'' SIG '' DQEBAQUABIIBAGZKrsXP3GFSOY4NJPIlFMgXqJfhKGHI
'' SIG '' CJmU1GYU861cAip/qN2CKR/ec1gnqY7yIY6Du/DAwG4d
'' SIG '' 5w8MAul+aRPWKubbkggVnZpuSjI3/4UWFfr3BdZ3MhY+
'' SIG '' 74GTAN4WKIYnC4cCJOxI2AF6KVv9JRYRg0wM2lJOp5M/
'' SIG '' svx2X+A07O3ICu/oZxtiCwJ1VKw3WEqkcPJwJlDo41W0
'' SIG '' TZM3JdHURqDDPKx7xt2A8aS/jubfPBhcLRTvk4uRQQGe
'' SIG '' aDAc8pczGR0tDheEyjTg7fCSH+HvrilK+8R6NhqGpvch
'' SIG '' WaqNQEJBHFBoV83rSUfadDoLLMQXnFyopHJpxczb4akm
'' SIG '' rUehghL+MIIS+gYKKwYBBAGCNwMDATGCEuowghLmBgkq
'' SIG '' hkiG9w0BBwKgghLXMIIS0wIBAzEPMA0GCWCGSAFlAwQC
'' SIG '' AQUAMIIBWQYLKoZIhvcNAQkQAQSgggFIBIIBRDCCAUAC
'' SIG '' AQEGCisGAQQBhFkKAwEwMTANBglghkgBZQMEAgEFAAQg
'' SIG '' uOwua7/SXMDYUhNbIrWZqxlmDfDsxZGU6I+P7ztT5uEC
'' SIG '' Bl+7/NBq5RgTMjAyMDEyMDIxMzI2MTguMTExWjAEgAIB
'' SIG '' 9KCB2KSB1TCB0jELMAkGA1UEBhMCVVMxEzARBgNVBAgT
'' SIG '' Cldhc2hpbmd0b24xEDAOBgNVBAcTB1JlZG1vbmQxHjAc
'' SIG '' BgNVBAoTFU1pY3Jvc29mdCBDb3Jwb3JhdGlvbjEtMCsG
'' SIG '' A1UECxMkTWljcm9zb2Z0IElyZWxhbmQgT3BlcmF0aW9u
'' SIG '' cyBMaW1pdGVkMSYwJAYDVQQLEx1UaGFsZXMgVFNTIEVT
'' SIG '' TjozQkQ0LTRCODAtNjlDMzElMCMGA1UEAxMcTWljcm9z
'' SIG '' b2Z0IFRpbWUtU3RhbXAgU2VydmljZaCCDk0wggT5MIID
'' SIG '' 4aADAgECAhMzAAABOxIbkiNSAlqlAAAAAAE7MA0GCSqG
'' SIG '' SIb3DQEBCwUAMHwxCzAJBgNVBAYTAlVTMRMwEQYDVQQI
'' SIG '' EwpXYXNoaW5ndG9uMRAwDgYDVQQHEwdSZWRtb25kMR4w
'' SIG '' HAYDVQQKExVNaWNyb3NvZnQgQ29ycG9yYXRpb24xJjAk
'' SIG '' BgNVBAMTHU1pY3Jvc29mdCBUaW1lLVN0YW1wIFBDQSAy
'' SIG '' MDEwMB4XDTIwMTAxNTE3MjgyMloXDTIyMDExMjE3Mjgy
'' SIG '' MlowgdIxCzAJBgNVBAYTAlVTMRMwEQYDVQQIEwpXYXNo
'' SIG '' aW5ndG9uMRAwDgYDVQQHEwdSZWRtb25kMR4wHAYDVQQK
'' SIG '' ExVNaWNyb3NvZnQgQ29ycG9yYXRpb24xLTArBgNVBAsT
'' SIG '' JE1pY3Jvc29mdCBJcmVsYW5kIE9wZXJhdGlvbnMgTGlt
'' SIG '' aXRlZDEmMCQGA1UECxMdVGhhbGVzIFRTUyBFU046M0JE
'' SIG '' NC00QjgwLTY5QzMxJTAjBgNVBAMTHE1pY3Jvc29mdCBU
'' SIG '' aW1lLVN0YW1wIFNlcnZpY2UwggEiMA0GCSqGSIb3DQEB
'' SIG '' AQUAA4IBDwAwggEKAoIBAQDjNtaV0NblMBgHAVLzwvdV
'' SIG '' AK2xT9nIXeeq0LD5VErh4bGY1d1AhSFt9wKsmyXt26R6
'' SIG '' vDy5KKWWn4AfmED2A5FzcgAkL43seVlZdf/mgCQ22tsx
'' SIG '' pkyFhYOEw8HhOUrDwp3A6nNlkXjGcOBpZZm5uX5CdYHa
'' SIG '' q3a58tlLrioL7ewaMDbwQ6LWftTOVqQf68XqWgIvljoh
'' SIG '' +re/kJOrsJ7j1kHZkJbBimQfjtxid69EzKbcQCz03T5C
'' SIG '' 8JpeI6iwsjFuGWq+MoArm/0kUJKMRN2lRopKBNJWVsNT
'' SIG '' 5Hv3BLO92xaA99NOTQ1uaJuvcDElRTv6AV924jQCjfqb
'' SIG '' ImQlCDXQIUQxAgMBAAGjggEbMIIBFzAdBgNVHQ4EFgQU
'' SIG '' x8+PzeLoV6CKVmQJQUW6vu/miJEwHwYDVR0jBBgwFoAU
'' SIG '' 1WM6XIoxkPNDe3xGG8UzaFqFbVUwVgYDVR0fBE8wTTBL
'' SIG '' oEmgR4ZFaHR0cDovL2NybC5taWNyb3NvZnQuY29tL3Br
'' SIG '' aS9jcmwvcHJvZHVjdHMvTWljVGltU3RhUENBXzIwMTAt
'' SIG '' MDctMDEuY3JsMFoGCCsGAQUFBwEBBE4wTDBKBggrBgEF
'' SIG '' BQcwAoY+aHR0cDovL3d3dy5taWNyb3NvZnQuY29tL3Br
'' SIG '' aS9jZXJ0cy9NaWNUaW1TdGFQQ0FfMjAxMC0wNy0wMS5j
'' SIG '' cnQwDAYDVR0TAQH/BAIwADATBgNVHSUEDDAKBggrBgEF
'' SIG '' BQcDCDANBgkqhkiG9w0BAQsFAAOCAQEAQbDxtOa5Na9V
'' SIG '' B/sxLUyv3O6QNUQx9acBb95j85X95W1tTYddgDCivyJ4
'' SIG '' Nn6+ZabNLj2zf1Vgb5AEC++jWxVomc1rZmQY1Cj2yfsI
'' SIG '' n6V9qntvzNCNwRXZjXRlk93XLYU+dd0jtpJtV28YiuTw
'' SIG '' F7DmJZqvphJBnHkrjKgkPWqXHn88Xub8oZ6Rym0x+PmH
'' SIG '' /7gdx4UT0yqdWJGckiNWKeYnObqpc1T5VBGq5rJGGLng
'' SIG '' D45nShij72GyRix5kWyGUJjofVUMUgMTqAEjf0wPsUbO
'' SIG '' dSyCpJy4rp5QIcS59fwVoQuPgluwmynqrRyleKRLxcqf
'' SIG '' nJvS6eZQVBdV7j2u08siFzCCBnEwggRZoAMCAQICCmEJ
'' SIG '' gSoAAAAAAAIwDQYJKoZIhvcNAQELBQAwgYgxCzAJBgNV
'' SIG '' BAYTAlVTMRMwEQYDVQQIEwpXYXNoaW5ndG9uMRAwDgYD
'' SIG '' VQQHEwdSZWRtb25kMR4wHAYDVQQKExVNaWNyb3NvZnQg
'' SIG '' Q29ycG9yYXRpb24xMjAwBgNVBAMTKU1pY3Jvc29mdCBS
'' SIG '' b290IENlcnRpZmljYXRlIEF1dGhvcml0eSAyMDEwMB4X
'' SIG '' DTEwMDcwMTIxMzY1NVoXDTI1MDcwMTIxNDY1NVowfDEL
'' SIG '' MAkGA1UEBhMCVVMxEzARBgNVBAgTCldhc2hpbmd0b24x
'' SIG '' EDAOBgNVBAcTB1JlZG1vbmQxHjAcBgNVBAoTFU1pY3Jv
'' SIG '' c29mdCBDb3Jwb3JhdGlvbjEmMCQGA1UEAxMdTWljcm9z
'' SIG '' b2Z0IFRpbWUtU3RhbXAgUENBIDIwMTAwggEiMA0GCSqG
'' SIG '' SIb3DQEBAQUAA4IBDwAwggEKAoIBAQCpHQ28dxGKOiDs
'' SIG '' /BOX9fp/aZRrdFQQ1aUKAIKF++18aEssX8XD5WHCdrc+
'' SIG '' Zitb8BVTJwQxH0EbGpUdzgkTjnxhMFmxMEQP8WCIhFRD
'' SIG '' DNdNuDgIs0Ldk6zWczBXJoKjRQ3Q6vVHgc2/JGAyWGBG
'' SIG '' 8lhHhjKEHnRhZ5FfgVSxz5NMksHEpl3RYRNuKMYa+YaA
'' SIG '' u99h/EbBJx0kZxJyGiGKr0tkiVBisV39dx898Fd1rL2K
'' SIG '' Qk1AUdEPnAY+Z3/1ZsADlkR+79BL/W7lmsqxqPJ6Kgox
'' SIG '' 8NpOBpG2iAg16HgcsOmZzTznL0S6p/TcZL2kAcEgCZN4
'' SIG '' zfy8wMlEXV4WnAEFTyJNAgMBAAGjggHmMIIB4jAQBgkr
'' SIG '' BgEEAYI3FQEEAwIBADAdBgNVHQ4EFgQU1WM6XIoxkPND
'' SIG '' e3xGG8UzaFqFbVUwGQYJKwYBBAGCNxQCBAweCgBTAHUA
'' SIG '' YgBDAEEwCwYDVR0PBAQDAgGGMA8GA1UdEwEB/wQFMAMB
'' SIG '' Af8wHwYDVR0jBBgwFoAU1fZWy4/oolxiaNE9lJBb186a
'' SIG '' GMQwVgYDVR0fBE8wTTBLoEmgR4ZFaHR0cDovL2NybC5t
'' SIG '' aWNyb3NvZnQuY29tL3BraS9jcmwvcHJvZHVjdHMvTWlj
'' SIG '' Um9vQ2VyQXV0XzIwMTAtMDYtMjMuY3JsMFoGCCsGAQUF
'' SIG '' BwEBBE4wTDBKBggrBgEFBQcwAoY+aHR0cDovL3d3dy5t
'' SIG '' aWNyb3NvZnQuY29tL3BraS9jZXJ0cy9NaWNSb29DZXJB
'' SIG '' dXRfMjAxMC0wNi0yMy5jcnQwgaAGA1UdIAEB/wSBlTCB
'' SIG '' kjCBjwYJKwYBBAGCNy4DMIGBMD0GCCsGAQUFBwIBFjFo
'' SIG '' dHRwOi8vd3d3Lm1pY3Jvc29mdC5jb20vUEtJL2RvY3Mv
'' SIG '' Q1BTL2RlZmF1bHQuaHRtMEAGCCsGAQUFBwICMDQeMiAd
'' SIG '' AEwAZQBnAGEAbABfAFAAbwBsAGkAYwB5AF8AUwB0AGEA
'' SIG '' dABlAG0AZQBuAHQALiAdMA0GCSqGSIb3DQEBCwUAA4IC
'' SIG '' AQAH5ohRDeLG4Jg/gXEDPZ2joSFvs+umzPUxvs8F4qn+
'' SIG '' +ldtGTCzwsVmyWrf9efweL3HqJ4l4/m87WtUVwgrUYJE
'' SIG '' Evu5U4zM9GASinbMQEBBm9xcF/9c+V4XNZgkVkt070IQ
'' SIG '' yK+/f8Z/8jd9Wj8c8pl5SpFSAK84Dxf1L3mBZdmptWvk
'' SIG '' x872ynoAb0swRCQiPM/tA6WWj1kpvLb9BOFwnzJKJ/1V
'' SIG '' ry/+tuWOM7tiX5rbV0Dp8c6ZZpCM/2pif93FSguRJuI5
'' SIG '' 7BlKcWOdeyFtw5yjojz6f32WapB4pm3S4Zz5Hfw42JT0
'' SIG '' xqUKloakvZ4argRCg7i1gJsiOCC1JeVk7Pf0v35jWSUP
'' SIG '' ei45V3aicaoGig+JFrphpxHLmtgOR5qAxdDNp9DvfYPw
'' SIG '' 4TtxCd9ddJgiCGHasFAeb73x4QDf5zEHpJM692VHeOj4
'' SIG '' qEir995yfmFrb3epgcunCaw5u+zGy9iCtHLNHfS4hQEe
'' SIG '' gPsbiSpUObJb2sgNVZl6h3M7COaYLeqN4DMuEin1wC9U
'' SIG '' JyH3yKxO2ii4sanblrKnQqLJzxlBTeCG+SqaoxFmMNO7
'' SIG '' dDJL32N79ZmKLxvHIa9Zta7cRDyXUHHXodLFVeNp3lfB
'' SIG '' 0d4wwP3M5k37Db9dT+mdHhk4L7zPWAUu7w2gUDXa7wkn
'' SIG '' HNWzfjUeCLraNtvTX4/edIhJEqGCAtcwggJAAgEBMIIB
'' SIG '' AKGB2KSB1TCB0jELMAkGA1UEBhMCVVMxEzARBgNVBAgT
'' SIG '' Cldhc2hpbmd0b24xEDAOBgNVBAcTB1JlZG1vbmQxHjAc
'' SIG '' BgNVBAoTFU1pY3Jvc29mdCBDb3Jwb3JhdGlvbjEtMCsG
'' SIG '' A1UECxMkTWljcm9zb2Z0IElyZWxhbmQgT3BlcmF0aW9u
'' SIG '' cyBMaW1pdGVkMSYwJAYDVQQLEx1UaGFsZXMgVFNTIEVT
'' SIG '' TjozQkQ0LTRCODAtNjlDMzElMCMGA1UEAxMcTWljcm9z
'' SIG '' b2Z0IFRpbWUtU3RhbXAgU2VydmljZaIjCgEBMAcGBSsO
'' SIG '' AwIaAxUAKDPC77kp1J1G63s+RXUk5YJcfeSggYMwgYCk
'' SIG '' fjB8MQswCQYDVQQGEwJVUzETMBEGA1UECBMKV2FzaGlu
'' SIG '' Z3RvbjEQMA4GA1UEBxMHUmVkbW9uZDEeMBwGA1UEChMV
'' SIG '' TWljcm9zb2Z0IENvcnBvcmF0aW9uMSYwJAYDVQQDEx1N
'' SIG '' aWNyb3NvZnQgVGltZS1TdGFtcCBQQ0EgMjAxMDANBgkq
'' SIG '' hkiG9w0BAQUFAAIFAONxr7gwIhgPMjAyMDEyMDIxNDE2
'' SIG '' MjRaGA8yMDIwMTIwMzE0MTYyNFowdzA9BgorBgEEAYRZ
'' SIG '' CgQBMS8wLTAKAgUA43GvuAIBADAKAgEAAgIZ3gIB/zAH
'' SIG '' AgEAAgIiCDAKAgUA43MBOAIBADA2BgorBgEEAYRZCgQC
'' SIG '' MSgwJjAMBgorBgEEAYRZCgMCoAowCAIBAAIDB6EgoQow
'' SIG '' CAIBAAIDAYagMA0GCSqGSIb3DQEBBQUAA4GBAAno/tpm
'' SIG '' QpEOxfSIctiumQc96wISMvG6i0rFAZ/ycjOAj1MK8usR
'' SIG '' 6o2DwN+Vld4bQdBmsz1rAzjmWaHdA/lklWb//ElHm9G5
'' SIG '' d4guRFDpJDvheW5Ua0LMKcEd1DSITbo05iMgF2h23hTR
'' SIG '' POqWJxZjBeXnfInI4nT0Tm8zS/uOLnUcMYIDDTCCAwkC
'' SIG '' AQEwgZMwfDELMAkGA1UEBhMCVVMxEzARBgNVBAgTCldh
'' SIG '' c2hpbmd0b24xEDAOBgNVBAcTB1JlZG1vbmQxHjAcBgNV
'' SIG '' BAoTFU1pY3Jvc29mdCBDb3Jwb3JhdGlvbjEmMCQGA1UE
'' SIG '' AxMdTWljcm9zb2Z0IFRpbWUtU3RhbXAgUENBIDIwMTAC
'' SIG '' EzMAAAE7EhuSI1ICWqUAAAAAATswDQYJYIZIAWUDBAIB
'' SIG '' BQCgggFKMBoGCSqGSIb3DQEJAzENBgsqhkiG9w0BCRAB
'' SIG '' BDAvBgkqhkiG9w0BCQQxIgQgx2vuVJsRizOtb3Sfgm9O
'' SIG '' 4hRkR9JO+CQeqAHOYZTNjjYwgfoGCyqGSIb3DQEJEAIv
'' SIG '' MYHqMIHnMIHkMIG9BCAcNuc3ecUm2AJt2Z/vQsVVt1Fr
'' SIG '' WO0AxlG9Fjtk4cRAHDCBmDCBgKR+MHwxCzAJBgNVBAYT
'' SIG '' AlVTMRMwEQYDVQQIEwpXYXNoaW5ndG9uMRAwDgYDVQQH
'' SIG '' EwdSZWRtb25kMR4wHAYDVQQKExVNaWNyb3NvZnQgQ29y
'' SIG '' cG9yYXRpb24xJjAkBgNVBAMTHU1pY3Jvc29mdCBUaW1l
'' SIG '' LVN0YW1wIFBDQSAyMDEwAhMzAAABOxIbkiNSAlqlAAAA
'' SIG '' AAE7MCIEINrpVgTgT6VyEW9W1yW0Wf0rOIGRyu1tx2uM
'' SIG '' bDv8ZrylMA0GCSqGSIb3DQEBCwUABIIBAKkOxT0nN0VJ
'' SIG '' l5QhbcYgG5yOEi54VxRcjyO50F/DI7BcvviABYtI3iEO
'' SIG '' +B2loQPgYadFp19+TiQxAI0c/x7ISv6QIe7BY07922n6
'' SIG '' SJJPWw6yC9Dc3RKDK8dH85yZKaS0UvXJOsFah+xpzcrV
'' SIG '' tZ7NGLYHHna6lZjngszmh61epeRK+x5t4FcrL68izTmb
'' SIG '' dQAD3dK2aeESbtR4nN534mmdHLKVhuHUHaroHwZeUawT
'' SIG '' ROsQtYHRmOGb4tvbfRdRA9ohauqdMFHCeuga7h/+VZC0
'' SIG '' muLw2G9byaPRf3o5Gyq/IyCxWcMqkLfPIzh68G+z+qbN
'' SIG '' +Ug2xYPHQG2kE/S2c3fYf7s=
'' SIG '' End signature block

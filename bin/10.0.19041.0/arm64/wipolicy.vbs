' Windows Installer utility to manage installer policy settings
' For use with Windows Scripting Host, CScript.exe or WScript.exe
' Copyright (c) Microsoft Corporation. All rights reserved.
' Demonstrates the use of the installer policy keys
' Policy can be configured by an administrator using the NT Group Policy Editor
'
Option Explicit

Dim policies(21, 4)
policies(1, 0)="LM" : policies(1, 1)="HKLM" : policies(1, 2)="Logging"              : policies(1, 3)="REG_SZ"    : policies(1, 4) = "Logging modes if not supplied by install, set of iwearucmpv"
policies(2, 0)="DO" : policies(2, 1)="HKLM" : policies(2, 2)="Debug"                : policies(2, 3)="REG_DWORD" : policies(2, 4) = "OutputDebugString: 1=debug output, 2=verbose debug output, 7=include command line"
policies(3, 0)="DI" : policies(3, 1)="HKLM" : policies(3, 2)="DisableMsi"           : policies(3, 3)="REG_DWORD" : policies(3, 4) = "1=Disable non-managed installs, 2=disable all installs"
policies(4, 0)="WT" : policies(4, 1)="HKLM" : policies(4, 2)="Timeout"              : policies(4, 3)="REG_DWORD" : policies(4, 4) = "Wait timeout in seconds in case of no activity"
policies(5, 0)="DB" : policies(5, 1)="HKLM" : policies(5, 2)="DisableBrowse"        : policies(5, 3)="REG_DWORD" : policies(5, 4) = "Disable user browsing of source locations if 1"
policies(6, 0)="AB" : policies(6, 1)="HKLM" : policies(6, 2)="AllowLockdownBrowse"  : policies(6, 3)="REG_DWORD" : policies(6, 4) = "Allow non-admin users to browse to new sources for managed applications if 1 - use is not recommended"
policies(7, 0)="AM" : policies(7, 1)="HKLM" : policies(7, 2)="AllowLockdownMedia"   : policies(7, 3)="REG_DWORD" : policies(7, 4) = "Allow non-admin users to browse to new media sources for managed applications if 1 - use is not recommended"
policies(8, 0)="AP" : policies(8, 1)="HKLM" : policies(8, 2)="AllowLockdownPatch"   : policies(8, 3)="REG_DWORD" : policies(8, 4) = "Allow non-admin users to apply small and minor update patches to managed applications if 1 - use is not recommended"
policies(9, 0)="DU" : policies(9, 1)="HKLM" : policies(9, 2)="DisableUserInstalls"  : policies(9, 3)="REG_DWORD" : policies(9, 4) = "Disable per-user installs if 1 - available on Windows Installer version 2.0 and later"
policies(10, 0)="DP" : policies(10, 1)="HKLM" : policies(10, 2)="DisablePatch"         : policies(10, 3)="REG_DWORD" : policies(10, 4) = "Disable patch application to all products if 1"
policies(11, 0)="UC" : policies(11, 1)="HKLM" : policies(11, 2)="EnableUserControl"    : policies(11, 3)="REG_DWORD" : policies(11, 4) = "All public properties sent to install service if 1"
policies(12, 0)="ER" : policies(12, 1)="HKLM" : policies(12, 2)="EnableAdminTSRemote"  : policies(12, 3)="REG_DWORD" : policies(12, 4) = "Allow admins to perform installs from terminal server client sessions if 1"
policies(13, 0)="LS" : policies(13, 1)="HKLM" : policies(13, 2)="LimitSystemRestoreCheckpointing" : policies(13, 3)="REG_DWORD" : policies(13, 4) = "Turn off creation of system restore check points on Windows XP if 1 - available on Windows Installer version 2.0 and later"
policies(14, 0)="SS" : policies(14, 1)="HKLM" : policies(14, 2)="SafeForScripting"     : policies(14, 3)="REG_DWORD" : policies(14, 4) = "Do not prompt when scripts within a webpage access Installer automation interface if 1 - use is not recommended"
policies(15, 0)="TP" : policies(15,1)="HKLM" : policies(15, 2)="TransformsSecure"     : policies(15, 3)="REG_DWORD" : policies(15, 4) = "Pin tranforms in secure location if 1 (only admin and system have write privileges to cache location)"
policies(16, 0)="EM" : policies(16, 1)="HKLM" : policies(16, 2)="AlwaysInstallElevated": policies(16, 3)="REG_DWORD" : policies(16, 4) = "System privileges if 1 and HKCU value also set - dangerous policy as non-admin users can install with elevated privileges if enabled"
policies(17, 0)="EU" : policies(17, 1)="HKCU" : policies(17, 2)="AlwaysInstallElevated": policies(17, 3)="REG_DWORD" : policies(17, 4) = "System privileges if 1 and HKLM value also set - dangerous policy as non-admin users can install with elevated privileges if enabled"
policies(18,0)="DR" : policies(18,1)="HKCU" : policies(18,2)="DisableRollback"      : policies(18,3)="REG_DWORD" : policies(18,4) = "Disable rollback if 1 - use is not recommended"
policies(19,0)="TS" : policies(19,1)="HKCU" : policies(19,2)="TransformsAtSource"   : policies(19,3)="REG_DWORD" : policies(19,4) = "Locate transforms at root of source image if 1"
policies(20,0)="SO" : policies(20,1)="HKCU" : policies(20,2)="SearchOrder"          : policies(20,3)="REG_SZ"    : policies(20,4) = "Search order of source types, set of n,m,u (default=nmu)"
policies(21,0)="DM" : policies(21,1)="HKCU" : policies(21,2)="DisableMedia"          : policies(21,3)="REG_DWORD"    : policies(21,4) = "Browsing to media sources is disabled"

Dim argCount:argCount = Wscript.Arguments.Count
Dim message, iPolicy, policyKey, policyValue, WshShell, policyCode
On Error Resume Next

' If no arguments supplied, then list all current policy settings
If argCount = 0 Then
	Set WshShell = WScript.CreateObject("WScript.Shell") : CheckError
	For iPolicy = 0 To UBound(policies)
		policyValue = ReadPolicyValue(iPolicy)
		If Not IsEmpty(policyValue) Then 'policy key present, else skip display
			If Not IsEmpty(message) Then message = message & vbLf
			message = message & policies(iPolicy,0) & ": " & policies(iPolicy,2) & "(" & policies(iPolicy,1) & ") = " & policyValue
		End If
	Next
	If IsEmpty(message) Then message = "No installer policies set"
	Wscript.Echo message
	Wscript.Quit 0
End If

' Check for ?, and show help message if found
policyCode = UCase(Wscript.Arguments(0))
If InStr(1, policyCode, "?", vbTextCompare) <> 0 Then
	message = "Windows Installer utility to manage installer policy settings" &_
		vbLf & " If no arguments are supplied, current policy settings in list will be reported" &_
		vbLf & " The 1st argument specifies the policy to set, using a code from the list below" &_
		vbLf & " The 2nd argument specifies the new policy setting, use """" to remove the policy" &_
		vbLf & " If the 2nd argument is not supplied, the current policy value will be reported"
	For iPolicy = 0 To UBound(policies)
		message = message & vbLf & policies(iPolicy,0) & ": " & policies(iPolicy,2) & "(" & policies(iPolicy,1) & ")  " & policies(iPolicy,4) & vbLf
	Next
	message = message & vblf & vblf & "Copyright (C) Microsoft Corporation.  All rights reserved."

	Wscript.Echo message
	Wscript.Quit 1
End If

' Policy code supplied, look up in array
For iPolicy = 0 To UBound(policies)
	If policies(iPolicy, 0) = policyCode Then Exit For
Next
If iPolicy > UBound(policies) Then Wscript.Echo "Unknown policy code: " & policyCode : Wscript.Quit 2
Set WshShell = WScript.CreateObject("WScript.Shell") : CheckError

' If no value supplied, then simply report current value
policyValue = ReadPolicyValue(iPolicy)
If IsEmpty(policyValue) Then policyValue = "Not present"
message = policies(iPolicy,0) & ": " & policies(iPolicy,2) & "(" & policies(iPolicy,1) & ") = " & policyValue
If argCount > 1 Then ' Value supplied, set policy
	policyValue = WritePolicyValue(iPolicy, Wscript.Arguments(1))
	If IsEmpty(policyValue) Then policyValue = "Not present"
	message = message & " --> " & policyValue
End If
Wscript.Echo message

Function ReadPolicyValue(iPolicy)
	On Error Resume Next
	Dim policyKey:policyKey = policies(iPolicy,1) & "\Software\Policies\Microsoft\Windows\Installer\" & policies(iPolicy,2)
	ReadPolicyValue = WshShell.RegRead(policyKey)
End Function

Function WritePolicyValue(iPolicy, policyValue)
	On Error Resume Next
	Dim policyKey:policyKey = policies(iPolicy,1) & "\Software\Policies\Microsoft\Windows\Installer\" & policies(iPolicy,2)
	If Len(policyValue) Then
		WshShell.RegWrite policyKey, policyValue, policies(iPolicy,3) : CheckError
		WritePolicyValue = policyValue
	ElseIf Not IsEmpty(ReadPolicyValue(iPolicy)) Then
		WshShell.RegDelete policyKey : CheckError
	End If
End Function

Sub CheckError
	Dim message, errRec
	If Err = 0 Then Exit Sub
	message = Err.Source & " " & Hex(Err) & ": " & Err.Description
	If Not installer Is Nothing Then
		Set errRec = installer.LastErrorRecord
		If Not errRec Is Nothing Then message = message & vbLf & errRec.FormatText
	End If
	Wscript.Echo message
	Wscript.Quit 2
End Sub

'' SIG '' Begin signature block
'' SIG '' MIIh9AYJKoZIhvcNAQcCoIIh5TCCIeECAQExDzANBglg
'' SIG '' hkgBZQMEAgEFADB3BgorBgEEAYI3AgEEoGkwZzAyBgor
'' SIG '' BgEEAYI3AgEeMCQCAQEEEE7wKRaZJ7VNj+Ws4Q8X66sC
'' SIG '' AQACAQACAQACAQACAQAwMTANBglghkgBZQMEAgEFAAQg
'' SIG '' /P2vh2Oob6dK4LJgJX9q0NCUL4Tr2otbVtqd2lYQZG6g
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
'' SIG '' IgQgG74cd1WwHhi9o902FBuqooOIxL5KiicynZhgW/cw
'' SIG '' OaswPAYKKwYBBAGCNwoDHDEuDCxQVi8xcDVsQkxIMEUy
'' SIG '' ZklwNVN1S3BkbDFnQ21LMEZHTTlHWDk5UUxJWHN3PTBa
'' SIG '' BgorBgEEAYI3AgEMMUwwSqAkgCIATQBpAGMAcgBvAHMA
'' SIG '' bwBmAHQAIABXAGkAbgBkAG8AdwBzoSKAIGh0dHA6Ly93
'' SIG '' d3cubWljcm9zb2Z0LmNvbS93aW5kb3dzMA0GCSqGSIb3
'' SIG '' DQEBAQUABIIBAGkFkjveCNyPK9bqKVFuhVBWWd5DZdpO
'' SIG '' SUsc9y3oAKB1E+TG/iVgDSxZwWfsQBLJ8uTg6tvA3TgB
'' SIG '' j+YQyVA2onxRisto1ANBATO0FjkUWJmPdEpoqWd+PbeA
'' SIG '' M0bb5QZVcUNcgTedOHISzS7ce6lPORIHbHPZDEqL7Wfn
'' SIG '' TpFXsMniRWLT54fCtO8EqC5cLpm6ccIm1N3bBRwHRX3E
'' SIG '' Hsb0i/ad6Vue3EA+zhP1h3DnafPteyg/FCnOAkyYSAvp
'' SIG '' JhhUQQHHUmTSWqGI8rg4+K9g0C3F4osfraAGnkKFrPQp
'' SIG '' YrZXAzP/qbOU/Su7eE4//4CY0gvZKvB8TjZBTGbLd5ht
'' SIG '' wFShghL+MIIS+gYKKwYBBAGCNwMDATGCEuowghLmBgkq
'' SIG '' hkiG9w0BBwKgghLXMIIS0wIBAzEPMA0GCWCGSAFlAwQC
'' SIG '' AQUAMIIBWQYLKoZIhvcNAQkQAQSgggFIBIIBRDCCAUAC
'' SIG '' AQEGCisGAQQBhFkKAwEwMTANBglghkgBZQMEAgEFAAQg
'' SIG '' biPCEruccpqcDFpfauak8q2JBke+thcohQFW1b4I2TEC
'' SIG '' Bl+7/NBqpxgTMjAyMDEyMDIxMzI2MTMuNTg1WjAEgAIB
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
'' SIG '' BDAvBgkqhkiG9w0BCQQxIgQgUSLHd6Qrj7zw3dUg7HI9
'' SIG '' qLnYDRVEBrQPRwHksWhsrz0wgfoGCyqGSIb3DQEJEAIv
'' SIG '' MYHqMIHnMIHkMIG9BCAcNuc3ecUm2AJt2Z/vQsVVt1Fr
'' SIG '' WO0AxlG9Fjtk4cRAHDCBmDCBgKR+MHwxCzAJBgNVBAYT
'' SIG '' AlVTMRMwEQYDVQQIEwpXYXNoaW5ndG9uMRAwDgYDVQQH
'' SIG '' EwdSZWRtb25kMR4wHAYDVQQKExVNaWNyb3NvZnQgQ29y
'' SIG '' cG9yYXRpb24xJjAkBgNVBAMTHU1pY3Jvc29mdCBUaW1l
'' SIG '' LVN0YW1wIFBDQSAyMDEwAhMzAAABOxIbkiNSAlqlAAAA
'' SIG '' AAE7MCIEINrpVgTgT6VyEW9W1yW0Wf0rOIGRyu1tx2uM
'' SIG '' bDv8ZrylMA0GCSqGSIb3DQEBCwUABIIBAH7IV1ImnG8w
'' SIG '' 8kK+XKWjsuZHuRLVODEhfHELFuYBBgXElbbCsdFZ/E30
'' SIG '' uMJN80Pq0vKeeV0bfDjdPNAoGC1qFzgQti2zjDBBim44
'' SIG '' tGOB4HhDZhLwCEJapOOQ5r01eU0pAJD0XR3ecGi8tt/d
'' SIG '' JAmwuxG7SEta4S7f/3DiWoYsduK4PaKsJhjtc9KvRMrE
'' SIG '' M8i0G+8tBvDCY+5oLomjFZmoPbxvHt3sq7b9bTlbj4cx
'' SIG '' OCc79iqJojuV8OSyD/UnjZ5hUROxFYspnVER78I0Dc1j
'' SIG '' i+hBMFaGRiTwUMdiJ2oq8mgMb7hPQvnZgDR3blJz3Mrk
'' SIG '' cMnP8HTRxj4bq4dEhaPoPY4=
'' SIG '' End signature block

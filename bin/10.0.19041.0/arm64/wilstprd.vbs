' Windows Installer utility to list registered products and product info
' For use with Windows Scripting Host, CScript.exe or WScript.exe
' Copyright (c) Microsoft Corporation. All rights reserved.
' Demonstrates the use of the product enumeration and ProductInfo methods and underlying APIs
'
Option Explicit

Const msiInstallStateNotUsed      = -7
Const msiInstallStateBadConfig    = -6
Const msiInstallStateIncomplete   = -5
Const msiInstallStateSourceAbsent = -4
Const msiInstallStateInvalidArg   = -2
Const msiInstallStateUnknown      = -1
Const msiInstallStateBroken       =  0
Const msiInstallStateAdvertised   =  1
Const msiInstallStateRemoved      =  1
Const msiInstallStateAbsent       =  2
Const msiInstallStateLocal        =  3
Const msiInstallStateSource       =  4
Const msiInstallStateDefault      =  5

' Connect to Windows Installer object
On Error Resume Next
Dim installer : Set installer = Nothing
Set installer = Wscript.CreateObject("WindowsInstaller.Installer") : CheckError

' If no arguments supplied, then list all installed or advertised products
Dim argCount:argCount = Wscript.Arguments.Count
If (argCount = 0) Then
	Dim product, products, info, productList, version
	On Error Resume Next
	Set products = installer.Products : CheckError
	For Each product In products
		version = DecodeVersion(installer.ProductInfo(product, "Version")) : CheckError
		info = product & " = " & installer.ProductInfo(product, "ProductName") & " " & version : CheckError
		If productList <> Empty Then productList = productList & vbNewLine & info Else productList = info
	Next
	If productList = Empty Then productList = "No products installed or advertised"
	Wscript.Echo productList
	Set products = Nothing
	Wscript.Quit 0
End If

' Check for ?, and show help message if found
Dim productName:productName = Wscript.Arguments(0)
If InStr(1, productName, "?", vbTextCompare) > 0 Then
	Wscript.Echo "Windows Installer utility to list registered products and product information" &_
		vbNewLine & " Lists all installed and advertised products if no arguments are specified" &_
		vbNewLine & " Else 1st argument is a product name (case-insensitive) or product ID (GUID)" &_
		vbNewLine & " If 2nd argument is missing or contains 'p', then product properties are listed" &_
		vbNewLine & " If 2nd argument contains 'f', features, parents, & installed states are listed" &_
		vbNewLine & " If 2nd argument contains 'c', installed components for that product are listed" &_
		vbNewLine & " If 2nd argument contains 'd', HKLM ""SharedDlls"" count for key files are listed" &_
		vbNewLine &_
		vbNewLine & "Copyright (C) Microsoft Corporation.  All rights reserved."
	Wscript.Quit 1
End If

' If Product name supplied, need to search for product code
Dim productCode, property, value, message
If Left(productName, 1) = "{" And Right(productName, 1) = "}" Then
	If installer.ProductState(productName) <> msiInstallStateUnknown Then productCode = UCase(productName)
Else
	For Each productCode In installer.Products : CheckError
		If LCase(installer.ProductInfo(productCode, "ProductName")) = LCase(productName) Then Exit For
	Next
End If
If IsEmpty(productCode) Then Wscript.Echo "Product is not registered: " & productName : Wscript.Quit 2

' Check option argument for type of information to display, default is properties
Dim optionFlag : If argcount > 1 Then optionFlag = LCase(Wscript.Arguments(1)) Else optionFlag = "p"
If InStr(1, optionFlag, "*", vbTextCompare) > 0 Then optionFlag = "pfcd"

If InStr(1, optionFlag, "p", vbTextCompare) > 0 Then
	message = "ProductCode = " & productCode
	For Each property In Array(_
			"Language",_
			"ProductName",_
			"PackageCode",_
			"Transforms",_
			"AssignmentType",_
			"PackageName",_
			"InstalledProductName",_
			"VersionString",_
			"RegCompany",_
			"RegOwner",_
			"ProductID",_
			"ProductIcon",_
			"InstallLocation",_
			"InstallSource",_
			"InstallDate",_
			"Publisher",_
			"LocalPackage",_
			"HelpLink",_
			"HelpTelephone",_
			"URLInfoAbout",_
			"URLUpdateInfo") : CheckError
		value = installer.ProductInfo(productCode, property) ': CheckError
		If Err <> 0 Then Err.Clear : value = Empty
		If (property = "Version") Then value = DecodeVersion(value)
		If value <> Empty Then message = message & vbNewLine & property & " = " & value
	Next
	Wscript.Echo message
End If

If InStr(1, optionFlag, "f", vbTextCompare) > 0 Then
	Dim feature, features, parent, state, featureInfo
	Set features = installer.Features(productCode)
	message = "---Features in product " & productCode & "---"
	For Each feature In features
		parent = installer.FeatureParent(productCode, feature) : CheckError
		If Len(parent) Then parent = " {" & parent & "}"
		state = installer.FeatureState(productCode, feature)
		Select Case(state)
			Case msiInstallStateBadConfig:    state = "Corrupt"
			Case msiInstallStateIncomplete:   state = "InProgress"
			Case msiInstallStateSourceAbsent: state = "SourceAbsent"
			Case msiInstallStateBroken:       state = "Broken"
			Case msiInstallStateAdvertised:   state = "Advertised"
			Case msiInstallStateAbsent:       state = "Uninstalled"
			Case msiInstallStateLocal:        state = "Local"
			Case msiInstallStateSource:       state = "Source"
			Case msiInstallStateDefault:      state = "Default"
			Case Else:                        state = "Unknown"
		End Select
		message = message & vbNewLine & feature & parent & " = " & state
	Next
	Set features = Nothing
	Wscript.Echo message
End If 

If InStr(1, optionFlag, "c", vbTextCompare) > 0 Then
	Dim component, components, client, clients, path
	Set components = installer.Components : CheckError
	message = "---Components in product " & productCode & "---"
	For Each component In components
		Set clients = installer.ComponentClients(component) : CheckError
		For Each client In Clients
			If client = productCode Then
				path = installer.ComponentPath(productCode, component) : CheckError
				message = message & vbNewLine & component & " = " & path
				Exit For
			End If
		Next
		Set clients = Nothing
	Next
	Set components = Nothing
	Wscript.Echo message
End If

If InStr(1, optionFlag, "d", vbTextCompare) > 0 Then
	Set components = installer.Components : CheckError
	message = "---Shared DLL counts for key files of " & productCode & "---"
	For Each component In components
		Set clients = installer.ComponentClients(component) : CheckError
		For Each client In Clients
			If client = productCode Then
				path = installer.ComponentPath(productCode, component) : CheckError
				If Len(path) = 0 Then path = "0"
				If AscW(path) >= 65 Then  ' ignore registry key paths
					value = installer.RegistryValue(2, "SOFTWARE\Microsoft\Windows\CurrentVersion\SharedDlls", path)
					If Err <> 0 Then value = 0 : Err.Clear
					message = message & vbNewLine & value & " = " & path
				End If
				Exit For
			End If
		Next
		Set clients = Nothing
	Next
	Set components = Nothing
	Wscript.Echo message
End If

Function DecodeVersion(version)
	version = CLng(version)
	DecodeVersion = version\65536\256 & "." & (version\65535 MOD 256) & "." & (version Mod 65536)
End Function

Sub CheckError
	Dim message, errRec
	If Err = 0 Then Exit Sub
	message = Err.Source & " " & Hex(Err) & ": " & Err.Description
	If Not installer Is Nothing Then
		Set errRec = installer.LastErrorRecord
		If Not errRec Is Nothing Then message = message & vbNewLine & errRec.FormatText
	End If
	Wscript.Echo message
	Wscript.Quit 2
End Sub

'' SIG '' Begin signature block
'' SIG '' MIIh9AYJKoZIhvcNAQcCoIIh5TCCIeECAQExDzANBglg
'' SIG '' hkgBZQMEAgEFADB3BgorBgEEAYI3AgEEoGkwZzAyBgor
'' SIG '' BgEEAYI3AgEeMCQCAQEEEE7wKRaZJ7VNj+Ws4Q8X66sC
'' SIG '' AQACAQACAQACAQACAQAwMTANBglghkgBZQMEAgEFAAQg
'' SIG '' +TYCWFk7lUqBMQntWKZoHVk2tbD50YMJse1NdDP1q+Gg
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
'' SIG '' IgQgV38KrmksrNZmRe2PIRhB+jOdW9FWVWoyVJi61CV/
'' SIG '' fDAwPAYKKwYBBAGCNwoDHDEuDCwwUEQ2Q1ZpTllLVFhH
'' SIG '' djROdjJzSHNDZ3Zrd0k4ZFB0c3VUZGx6NjR6ZjhvPTBa
'' SIG '' BgorBgEEAYI3AgEMMUwwSqAkgCIATQBpAGMAcgBvAHMA
'' SIG '' bwBmAHQAIABXAGkAbgBkAG8AdwBzoSKAIGh0dHA6Ly93
'' SIG '' d3cubWljcm9zb2Z0LmNvbS93aW5kb3dzMA0GCSqGSIb3
'' SIG '' DQEBAQUABIIBAEgVHMhVL+2xkjxatnoFsk40hifcaoPS
'' SIG '' 6RwAyPEz2kfgBQE3Xt+i5xpwwHNxDEe4jXiEgV4oD1Ak
'' SIG '' rN0Wezl5TgIPvI9qVsb3u5QfUxGtlCN3zf20MuGzujgh
'' SIG '' ieOk1/q/FFefLGjhg/W8A1x9RHjfS63zhXMKN0hfriGA
'' SIG '' q/i5bmi0r/QaWbMYbXrztKB/jYHc1waSckjtnsGEqxzf
'' SIG '' ktI6N300LrI3wtQlnoOIxE9TfQclX2ofTwUTEkp7J+2+
'' SIG '' YgfQRjoZrFPdGUJ3iFd2Gy/Ve/fnv5KUc6vQ5R1B7+Jg
'' SIG '' tylOo+4W3iOl2h4sQAZjPzfD5gUubHMAoMSUUviK/PSh
'' SIG '' 7guhghL+MIIS+gYKKwYBBAGCNwMDATGCEuowghLmBgkq
'' SIG '' hkiG9w0BBwKgghLXMIIS0wIBAzEPMA0GCWCGSAFlAwQC
'' SIG '' AQUAMIIBWQYLKoZIhvcNAQkQAQSgggFIBIIBRDCCAUAC
'' SIG '' AQEGCisGAQQBhFkKAwEwMTANBglghkgBZQMEAgEFAAQg
'' SIG '' VMODH300umWL3w/yJqWY2U+dKXoRRBkRnt8NbU0ox04C
'' SIG '' Bl+8CdKGXxgTMjAyMDEyMDIxMzI2MTQuMjMxWjAEgAIB
'' SIG '' 9KCB2KSB1TCB0jELMAkGA1UEBhMCVVMxEzARBgNVBAgT
'' SIG '' Cldhc2hpbmd0b24xEDAOBgNVBAcTB1JlZG1vbmQxHjAc
'' SIG '' BgNVBAoTFU1pY3Jvc29mdCBDb3Jwb3JhdGlvbjEtMCsG
'' SIG '' A1UECxMkTWljcm9zb2Z0IElyZWxhbmQgT3BlcmF0aW9u
'' SIG '' cyBMaW1pdGVkMSYwJAYDVQQLEx1UaGFsZXMgVFNTIEVT
'' SIG '' TjpBMjQwLTRCODItMTMwRTElMCMGA1UEAxMcTWljcm9z
'' SIG '' b2Z0IFRpbWUtU3RhbXAgU2VydmljZaCCDk0wggT5MIID
'' SIG '' 4aADAgECAhMzAAABP+F+7aPY/7/ZAAAAAAE/MA0GCSqG
'' SIG '' SIb3DQEBCwUAMHwxCzAJBgNVBAYTAlVTMRMwEQYDVQQI
'' SIG '' EwpXYXNoaW5ndG9uMRAwDgYDVQQHEwdSZWRtb25kMR4w
'' SIG '' HAYDVQQKExVNaWNyb3NvZnQgQ29ycG9yYXRpb24xJjAk
'' SIG '' BgNVBAMTHU1pY3Jvc29mdCBUaW1lLVN0YW1wIFBDQSAy
'' SIG '' MDEwMB4XDTIwMTAxNTE3MjgyNloXDTIyMDExMjE3Mjgy
'' SIG '' NlowgdIxCzAJBgNVBAYTAlVTMRMwEQYDVQQIEwpXYXNo
'' SIG '' aW5ndG9uMRAwDgYDVQQHEwdSZWRtb25kMR4wHAYDVQQK
'' SIG '' ExVNaWNyb3NvZnQgQ29ycG9yYXRpb24xLTArBgNVBAsT
'' SIG '' JE1pY3Jvc29mdCBJcmVsYW5kIE9wZXJhdGlvbnMgTGlt
'' SIG '' aXRlZDEmMCQGA1UECxMdVGhhbGVzIFRTUyBFU046QTI0
'' SIG '' MC00QjgyLTEzMEUxJTAjBgNVBAMTHE1pY3Jvc29mdCBU
'' SIG '' aW1lLVN0YW1wIFNlcnZpY2UwggEiMA0GCSqGSIb3DQEB
'' SIG '' AQUAA4IBDwAwggEKAoIBAQDtRdVOZW0fiQdnowDuykTB
'' SIG '' XS5uWq6XQ6Csh903jFEQo7A6O7nZFv3NGtMWQrfjwsuj
'' SIG '' 7ihrWNZIwK6IEYY8RLshCd+vI5wdZG4S2mNAyPFKhDEj
'' SIG '' Fenc4IsRf1tk0ToPdm7DBuLn1o/OqQWgv15WrkzbI2Dw
'' SIG '' wh7M1e7bf0Dh59GoJj8OF+vD8gjvHG4KmvahVdHtNhFb
'' SIG '' qRNRp5Ygj+yPsXdLJRmIGDlAyYw7QokfYWME+OyzYrjn
'' SIG '' BKNB46LFVHngdl15+wsEydfzYks3lCUOjUD/Kw0yF+xI
'' SIG '' AHe8OgDNVWpqwIjmv/R3GCrVaxVyNrBvn2uDOupaozBC
'' SIG '' 1/im0hnMVgylAgMBAAGjggEbMIIBFzAdBgNVHQ4EFgQU
'' SIG '' vDoLzBGjE6WM4euib8kWjDuYgWswHwYDVR0jBBgwFoAU
'' SIG '' 1WM6XIoxkPNDe3xGG8UzaFqFbVUwVgYDVR0fBE8wTTBL
'' SIG '' oEmgR4ZFaHR0cDovL2NybC5taWNyb3NvZnQuY29tL3Br
'' SIG '' aS9jcmwvcHJvZHVjdHMvTWljVGltU3RhUENBXzIwMTAt
'' SIG '' MDctMDEuY3JsMFoGCCsGAQUFBwEBBE4wTDBKBggrBgEF
'' SIG '' BQcwAoY+aHR0cDovL3d3dy5taWNyb3NvZnQuY29tL3Br
'' SIG '' aS9jZXJ0cy9NaWNUaW1TdGFQQ0FfMjAxMC0wNy0wMS5j
'' SIG '' cnQwDAYDVR0TAQH/BAIwADATBgNVHSUEDDAKBggrBgEF
'' SIG '' BQcDCDANBgkqhkiG9w0BAQsFAAOCAQEAn7L6YA4urnhN
'' SIG '' jZYOIKRgQ50BQJmYT6OOa7KPkdC6qUZ+M6J5eOBV3JiQ
'' SIG '' ETDdK94g8PbLm29Dfw9J8FGxh1qmrEOsBvAyUWEwcZel
'' SIG '' XK9cgbhoQRVk9T8UvDDRtLV5qQX3mYgwW0v9iHWUbU1Q
'' SIG '' 1erzInx3nijrCEUVy7/LYG9Lz7QscVTRJM2JHzxnkfOO
'' SIG '' 8PPIqmhy3faH4Rt0/Bbf3P1VTh0Aw2vmlxySaIDvu9Zy
'' SIG '' kUF2HVP7S4a+AqqZIe8UDZbMhmQmjbqDMAihUakT/pJF
'' SIG '' tRajkRxISWuAC+mWDQoh6VCEGkX7lSMNdXzO4+0zkFPe
'' SIG '' Ib7zn85NJS5PCEW+ouikIjCCBnEwggRZoAMCAQICCmEJ
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
'' SIG '' TjpBMjQwLTRCODItMTMwRTElMCMGA1UEAxMcTWljcm9z
'' SIG '' b2Z0IFRpbWUtU3RhbXAgU2VydmljZaIjCgEBMAcGBSsO
'' SIG '' AwIaAxUATtc0IX/WxyXJgKAkj4JoyAI6IhiggYMwgYCk
'' SIG '' fjB8MQswCQYDVQQGEwJVUzETMBEGA1UECBMKV2FzaGlu
'' SIG '' Z3RvbjEQMA4GA1UEBxMHUmVkbW9uZDEeMBwGA1UEChMV
'' SIG '' TWljcm9zb2Z0IENvcnBvcmF0aW9uMSYwJAYDVQQDEx1N
'' SIG '' aWNyb3NvZnQgVGltZS1TdGFtcCBQQ0EgMjAxMDANBgkq
'' SIG '' hkiG9w0BAQUFAAIFAONxvLkwIhgPMjAyMDEyMDIxNTEx
'' SIG '' NTNaGA8yMDIwMTIwMzE1MTE1M1owdzA9BgorBgEEAYRZ
'' SIG '' CgQBMS8wLTAKAgUA43G8uQIBADAKAgEAAgITIQIB/zAH
'' SIG '' AgEAAgISYTAKAgUA43MOOQIBADA2BgorBgEEAYRZCgQC
'' SIG '' MSgwJjAMBgorBgEEAYRZCgMCoAowCAIBAAIDB6EgoQow
'' SIG '' CAIBAAIDAYagMA0GCSqGSIb3DQEBBQUAA4GBABYPnLy3
'' SIG '' nxqJzIWv3HIUu6uN0MJaRaTfOTNe5vlxCAZ620vlu2Sj
'' SIG '' 4wm4LNFpOoyLERPN+KNRHTqCAtxjEK1JGs3vxsaQ+/1M
'' SIG '' fMfxdTBA6BZHjxsmWodaf1SFLA1tXri6CSg51KbTuFBS
'' SIG '' NCke3WMVeZss8LOawI1AiFBLQTJ27/0HMYIDDTCCAwkC
'' SIG '' AQEwgZMwfDELMAkGA1UEBhMCVVMxEzARBgNVBAgTCldh
'' SIG '' c2hpbmd0b24xEDAOBgNVBAcTB1JlZG1vbmQxHjAcBgNV
'' SIG '' BAoTFU1pY3Jvc29mdCBDb3Jwb3JhdGlvbjEmMCQGA1UE
'' SIG '' AxMdTWljcm9zb2Z0IFRpbWUtU3RhbXAgUENBIDIwMTAC
'' SIG '' EzMAAAE/4X7to9j/v9kAAAAAAT8wDQYJYIZIAWUDBAIB
'' SIG '' BQCgggFKMBoGCSqGSIb3DQEJAzENBgsqhkiG9w0BCRAB
'' SIG '' BDAvBgkqhkiG9w0BCQQxIgQgWadlQzASlVCXd49TllnB
'' SIG '' +OoaCgvQOHlOWu7QiGxVmUAwgfoGCyqGSIb3DQEJEAIv
'' SIG '' MYHqMIHnMIHkMIG9BCBEO1mvnBV4wdymodq1lJk+zJvC
'' SIG '' avlCCIy8Wz4jGSlLIDCBmDCBgKR+MHwxCzAJBgNVBAYT
'' SIG '' AlVTMRMwEQYDVQQIEwpXYXNoaW5ndG9uMRAwDgYDVQQH
'' SIG '' EwdSZWRtb25kMR4wHAYDVQQKExVNaWNyb3NvZnQgQ29y
'' SIG '' cG9yYXRpb24xJjAkBgNVBAMTHU1pY3Jvc29mdCBUaW1l
'' SIG '' LVN0YW1wIFBDQSAyMDEwAhMzAAABP+F+7aPY/7/ZAAAA
'' SIG '' AAE/MCIEIKfHrImRat0Xhin1Cb8OLxUt9je8vLL6RIs8
'' SIG '' 5zbHNpZ0MA0GCSqGSIb3DQEBCwUABIIBACE1rlYv3JAb
'' SIG '' u5W8P3SOf4567PG7X8N6nKU8/4P+JQKPEuqp6hRryRa4
'' SIG '' v4Br5vqgW0ZETCgeWaPb2GJWKBggPv1JwNIFhrLQYaHB
'' SIG '' p/gStF5ht8s1KaEqEmj9cnHrIX1A/VXh450eN/kuxciO
'' SIG '' OZU65ls3Bhr17o7fBRbyHtR1ShSul29le19xRn5tV5TF
'' SIG '' wQPVYxzQp6TNk+2uQhGJFiYGs4mgJgDWBNwdnYrtJL+T
'' SIG '' FqzsQxr99L5YiG38oPCVd6GAEmX1nFysYYv6p6uoIhMT
'' SIG '' 5us3Xf/dPayUP+kDMLW/d+979Sp0fnl197NpW+4yRAxe
'' SIG '' nDqAhCBCaGpVW8yPCWQNu/I=
'' SIG '' End signature block

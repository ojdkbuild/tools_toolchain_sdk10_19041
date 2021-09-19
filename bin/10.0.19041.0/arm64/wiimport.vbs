' Windows Installer database table import for use with Windows Scripting Host
' Copyright (c) Microsoft Corporation. All rights reserved.
' Demonstrates the use of the Database.Import method and MsiDatabaseImport API
'
Option Explicit

Const msiOpenDatabaseModeReadOnly     = 0
Const msiOpenDatabaseModeTransact     = 1
Const msiOpenDatabaseModeCreate       = 3
Const ForAppending = 8
Const ForReading = 1
Const ForWriting = 2
Const TristateTrue = -1

Dim argCount:argCount = Wscript.Arguments.Count
Dim iArg:iArg = 0
If (argCount < 3) Then
	Wscript.Echo "Windows Installer database table import utility" &_
		vbNewLine & " 1st argument is the path to MSI database (installer package)" &_
		vbNewLine & " 2nd argument is the path to folder containing the imported files" &_
		vbNewLine & " Subseqent arguments are names of archive files to import" &_
		vbNewLine & " Wildcards, such as *.idt, can be used to import multiple files" &_
		vbNewLine & " Specify /c or -c anywhere before file list to create new database" &_
		vbNewLine &_
		vbNewLine & "Copyright (C) Microsoft Corporation.  All rights reserved."
	Wscript.Quit 1
End If

' Connect to Windows Installer object
On Error Resume Next
Dim installer : Set installer = Nothing
Set installer = Wscript.CreateObject("WindowsInstaller.Installer") : CheckError

Dim openMode:openMode = msiOpenDatabaseModeTransact
Dim databasePath:databasePath = NextArgument
Dim folder:folder = NextArgument

Dim WshShell, fileSys
Set WshShell = Wscript.CreateObject("Wscript.Shell") : CheckError
Set fileSys = CreateObject("Scripting.FileSystemObject") : CheckError

' Open database and process list of files
Dim database, table
Set database = installer.OpenDatabase(databasePath, openMode) : CheckError
While iArg < argCount
	table = NextArgument
	' Check file name for wildcard specification
	If (InStr(1,table,"*",vbTextCompare) <> 0) Or (InStr(1,table,"?",vbTextCompare) <> 0) Then
		' Obtain list of files matching wildcard specification
		Dim file, tempFilePath
		tempFilePath = WshShell.ExpandEnvironmentStrings("%TEMP%") & "\dir.tmp"
		WshShell.Run "cmd.exe /U /c dir /b " & folder & "\" & table & ">" & tempFilePath, 0, True : CheckError
		Set file = fileSys.OpenTextFile(tempFilePath, ForReading, False, TristateTrue) : CheckError
		' Import each file in directory list
		Do While file.AtEndOfStream <> True
			table = file.ReadLine
			database.Import folder, table : CheckError
		Loop
		file.Close
		fileSys.DeleteFile(tempFilePath)
	Else
		database.Import folder, table : CheckError
	End If
Wend
database.Commit 'commit changes if no import errors
Wscript.Quit 0

Function NextArgument
	Dim arg, chFlag
	Do
		arg = Wscript.Arguments(iArg)
		iArg = iArg + 1
		chFlag = AscW(arg)
		If (chFlag = AscW("/")) Or (chFlag = AscW("-")) Then
			chFlag = UCase(Right(arg, Len(arg)-1))
			If chFlag = "C" Then 
				openMode = msiOpenDatabaseModeCreate
			Else
				Wscript.Echo "Invalid option flag:", arg : Wscript.Quit 1
			End If
		Else
			Exit Do
		End If
	Loop
	NextArgument = arg
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
'' SIG '' MIIh8QYJKoZIhvcNAQcCoIIh4jCCId4CAQExDzANBglg
'' SIG '' hkgBZQMEAgEFADB3BgorBgEEAYI3AgEEoGkwZzAyBgor
'' SIG '' BgEEAYI3AgEeMCQCAQEEEE7wKRaZJ7VNj+Ws4Q8X66sC
'' SIG '' AQACAQACAQACAQACAQAwMTANBglghkgBZQMEAgEFAAQg
'' SIG '' URtattTTdos4rg+Jt96T7zPQ8Pzvx4qAdD0rt5bwgTmg
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
'' SIG '' Bmrm1MbfI5qWdcUxghXIMIIVxAIBATCBlTB+MQswCQYD
'' SIG '' VQQGEwJVUzETMBEGA1UECBMKV2FzaGluZ3RvbjEQMA4G
'' SIG '' A1UEBxMHUmVkbW9uZDEeMBwGA1UEChMVTWljcm9zb2Z0
'' SIG '' IENvcnBvcmF0aW9uMSgwJgYDVQQDEx9NaWNyb3NvZnQg
'' SIG '' Q29kZSBTaWduaW5nIFBDQSAyMDEwAhMzAAADg+rbu9lv
'' SIG '' Ibj6AAAAAAODMA0GCWCGSAFlAwQCAQUAoIIBBDAZBgkq
'' SIG '' hkiG9w0BCQMxDAYKKwYBBAGCNwIBBDAcBgorBgEEAYI3
'' SIG '' AgELMQ4wDAYKKwYBBAGCNwIBFTAvBgkqhkiG9w0BCQQx
'' SIG '' IgQg7eWUfGzAc/5A7zipkVLl2TNPbIlzesQq/vdNLq54
'' SIG '' wLAwPAYKKwYBBAGCNwoDHDEuDCxzSGN4TXc1bWttUzVL
'' SIG '' bHF6Q200ZkZ6SHRTR0ZFcGNoL1RJREMvb1dVNDlrPTBa
'' SIG '' BgorBgEEAYI3AgEMMUwwSqAkgCIATQBpAGMAcgBvAHMA
'' SIG '' bwBmAHQAIABXAGkAbgBkAG8AdwBzoSKAIGh0dHA6Ly93
'' SIG '' d3cubWljcm9zb2Z0LmNvbS93aW5kb3dzMA0GCSqGSIb3
'' SIG '' DQEBAQUABIIBAIckLImQkES5/sdsuCyhNRbLtvnrjnbc
'' SIG '' OtFFEXchFzR5IYJ7zr64xL6+n3+D+lv+L5PyAu1dkhTP
'' SIG '' oXmvOcC1/goTA8OeomHTZiKHx6EPd/ogeWUvvolxj2A+
'' SIG '' OvEg6u7RXtkdRLwIMcTmYCHnuwmipmKuSs+uRU9QJiwg
'' SIG '' BBzMobpAA3o9xLAslZCvMpA786hVhOrxeVHzWGF0dR+7
'' SIG '' axDlGP6cb8swsGkIGNsPfzr27aRQdeh9JW5wz6qayRHc
'' SIG '' G1FyEvr+645/RlQcmkNzgtU6aMxMxJVaPqe0jcpCh1xp
'' SIG '' 8/W2GdMqJuDE2Itw6GWCzbv56vWJ9exa39ZE1MxKGnvv
'' SIG '' 6RKhghL7MIIS9wYKKwYBBAGCNwMDATGCEucwghLjBgkq
'' SIG '' hkiG9w0BBwKgghLUMIIS0AIBAzEPMA0GCWCGSAFlAwQC
'' SIG '' AQUAMIIBWQYLKoZIhvcNAQkQAQSgggFIBIIBRDCCAUAC
'' SIG '' AQEGCisGAQQBhFkKAwEwMTANBglghkgBZQMEAgEFAAQg
'' SIG '' gLqE9A16TGMsfmroNuezZLSF05zsQCzOqi02VG9KlMQC
'' SIG '' Bl+8B0w0bRgTMjAyMDEyMDIxMzI2MTMuNjU3WjAEgAIB
'' SIG '' 9KCB2KSB1TCB0jELMAkGA1UEBhMCVVMxEzARBgNVBAgT
'' SIG '' Cldhc2hpbmd0b24xEDAOBgNVBAcTB1JlZG1vbmQxHjAc
'' SIG '' BgNVBAoTFU1pY3Jvc29mdCBDb3Jwb3JhdGlvbjEtMCsG
'' SIG '' A1UECxMkTWljcm9zb2Z0IElyZWxhbmQgT3BlcmF0aW9u
'' SIG '' cyBMaW1pdGVkMSYwJAYDVQQLEx1UaGFsZXMgVFNTIEVT
'' SIG '' Tjo4NkRGLTRCQkMtOTMzNTElMCMGA1UEAxMcTWljcm9z
'' SIG '' b2Z0IFRpbWUtU3RhbXAgU2VydmljZaCCDkowggT5MIID
'' SIG '' 4aADAgECAhMzAAABPs7Kd1LF9zQrAAAAAAE+MA0GCSqG
'' SIG '' SIb3DQEBCwUAMHwxCzAJBgNVBAYTAlVTMRMwEQYDVQQI
'' SIG '' EwpXYXNoaW5ndG9uMRAwDgYDVQQHEwdSZWRtb25kMR4w
'' SIG '' HAYDVQQKExVNaWNyb3NvZnQgQ29ycG9yYXRpb24xJjAk
'' SIG '' BgNVBAMTHU1pY3Jvc29mdCBUaW1lLVN0YW1wIFBDQSAy
'' SIG '' MDEwMB4XDTIwMTAxNTE3MjgyNVoXDTIyMDExMjE3Mjgy
'' SIG '' NVowgdIxCzAJBgNVBAYTAlVTMRMwEQYDVQQIEwpXYXNo
'' SIG '' aW5ndG9uMRAwDgYDVQQHEwdSZWRtb25kMR4wHAYDVQQK
'' SIG '' ExVNaWNyb3NvZnQgQ29ycG9yYXRpb24xLTArBgNVBAsT
'' SIG '' JE1pY3Jvc29mdCBJcmVsYW5kIE9wZXJhdGlvbnMgTGlt
'' SIG '' aXRlZDEmMCQGA1UECxMdVGhhbGVzIFRTUyBFU046ODZE
'' SIG '' Ri00QkJDLTkzMzUxJTAjBgNVBAMTHE1pY3Jvc29mdCBU
'' SIG '' aW1lLVN0YW1wIFNlcnZpY2UwggEiMA0GCSqGSIb3DQEB
'' SIG '' AQUAA4IBDwAwggEKAoIBAQC8VMTIPNl+nCzjTiBILSS3
'' SIG '' hVLJf+9rHA5+uLz2BB3G99A2+9ABF5spHemWofPRkdlb
'' SIG '' 5uYXHIa1OH3PDbQtJ2kxxZgMVzWvM+4m9M0CcOQrJA/5
'' SIG '' OqtbuP+UOUItuqLy5ujgSpKmQetrRm3XmPav8gkZlu7d
'' SIG '' BpFjqpgxnHGSTDhjm5sDBXcTWn5M3MWDyfOAn2TAQzjG
'' SIG '' 9kB/02EeEzYr+PHT3bGYrHIV+nRfS1uhj13U7KF0JeXy
'' SIG '' yk6KATfaDzMfXZjY1dN8jjXjUtBT710o4pDtgUXWTCh+
'' SIG '' 4YbDExTQKwOKY4NaCvpUVVw0N3a1Bsa5uB18sEYQF+N7
'' SIG '' Q/Kg45cQ7WbhAgMBAAGjggEbMIIBFzAdBgNVHQ4EFgQU
'' SIG '' k1rznfi70GIta/C1tlQOtoaI/XswHwYDVR0jBBgwFoAU
'' SIG '' 1WM6XIoxkPNDe3xGG8UzaFqFbVUwVgYDVR0fBE8wTTBL
'' SIG '' oEmgR4ZFaHR0cDovL2NybC5taWNyb3NvZnQuY29tL3Br
'' SIG '' aS9jcmwvcHJvZHVjdHMvTWljVGltU3RhUENBXzIwMTAt
'' SIG '' MDctMDEuY3JsMFoGCCsGAQUFBwEBBE4wTDBKBggrBgEF
'' SIG '' BQcwAoY+aHR0cDovL3d3dy5taWNyb3NvZnQuY29tL3Br
'' SIG '' aS9jZXJ0cy9NaWNUaW1TdGFQQ0FfMjAxMC0wNy0wMS5j
'' SIG '' cnQwDAYDVR0TAQH/BAIwADATBgNVHSUEDDAKBggrBgEF
'' SIG '' BQcDCDANBgkqhkiG9w0BAQsFAAOCAQEAprP5EX1an4aS
'' SIG '' uRWPpxjl2MJ1V6kkXK58AEnWoqUJZeE6hgBwHvDtnHNE
'' SIG '' LhnaJjhtz1BT3exrZgPCFDAU96p8pl9ZKSaty6zj1AH0
'' SIG '' QY9z0XAiB8FArYAm2FpgTKxNrBLjR/rJzrD/Jui0ByWo
'' SIG '' UCv4E8O3TMZmgTG8ZzxmlUBmm9LJdvMYu4q2bwr5HvdU
'' SIG '' LgNSnixEVyTULHwgu9h1hI1io5HKHQbCLe/gdabDoe61
'' SIG '' p8U50WNopARxKyfRI0t9jbmo6qe7oMv40CjvPeoPR4EM
'' SIG '' hKKVahvl2WUNw41+y731QS06ett2Xb3bIY0jLGKWkjxc
'' SIG '' Y2AZxnEo3pWosHEC4qVY5jCCBnEwggRZoAMCAQICCmEJ
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
'' SIG '' HNWzfjUeCLraNtvTX4/edIhJEqGCAtQwggI9AgEBMIIB
'' SIG '' AKGB2KSB1TCB0jELMAkGA1UEBhMCVVMxEzARBgNVBAgT
'' SIG '' Cldhc2hpbmd0b24xEDAOBgNVBAcTB1JlZG1vbmQxHjAc
'' SIG '' BgNVBAoTFU1pY3Jvc29mdCBDb3Jwb3JhdGlvbjEtMCsG
'' SIG '' A1UECxMkTWljcm9zb2Z0IElyZWxhbmQgT3BlcmF0aW9u
'' SIG '' cyBMaW1pdGVkMSYwJAYDVQQLEx1UaGFsZXMgVFNTIEVT
'' SIG '' Tjo4NkRGLTRCQkMtOTMzNTElMCMGA1UEAxMcTWljcm9z
'' SIG '' b2Z0IFRpbWUtU3RhbXAgU2VydmljZaIjCgEBMAcGBSsO
'' SIG '' AwIaAxUAoEwV6PTGMJOMKTWxN1Mpr5PMkNSggYMwgYCk
'' SIG '' fjB8MQswCQYDVQQGEwJVUzETMBEGA1UECBMKV2FzaGlu
'' SIG '' Z3RvbjEQMA4GA1UEBxMHUmVkbW9uZDEeMBwGA1UEChMV
'' SIG '' TWljcm9zb2Z0IENvcnBvcmF0aW9uMSYwJAYDVQQDEx1N
'' SIG '' aWNyb3NvZnQgVGltZS1TdGFtcCBQQ0EgMjAxMDANBgkq
'' SIG '' hkiG9w0BAQUFAAIFAONxujUwIhgPMjAyMDEyMDIxNTAx
'' SIG '' MDlaGA8yMDIwMTIwMzE1MDEwOVowdDA6BgorBgEEAYRZ
'' SIG '' CgQBMSwwKjAKAgUA43G6NQIBADAHAgEAAgIQBjAHAgEA
'' SIG '' AgIgaDAKAgUA43MLtQIBADA2BgorBgEEAYRZCgQCMSgw
'' SIG '' JjAMBgorBgEEAYRZCgMCoAowCAIBAAIDB6EgoQowCAIB
'' SIG '' AAIDAYagMA0GCSqGSIb3DQEBBQUAA4GBAHFH2reijpqf
'' SIG '' eolQkKcnmrK51gbwihbJzmY0JvWgQw6VV6ocqkNzgwv5
'' SIG '' zvPyWwdeCdqLskpuaINTjNbevNBR1IcM4O6jA6VY5U4X
'' SIG '' 9O3jvMBSGX6h/xFo3DMhAXCQFmpJbMThKOTwJlyvvB77
'' SIG '' IzMW2h0dF8WBPBJrJioqOcQHsAO6MYIDDTCCAwkCAQEw
'' SIG '' gZMwfDELMAkGA1UEBhMCVVMxEzARBgNVBAgTCldhc2hp
'' SIG '' bmd0b24xEDAOBgNVBAcTB1JlZG1vbmQxHjAcBgNVBAoT
'' SIG '' FU1pY3Jvc29mdCBDb3Jwb3JhdGlvbjEmMCQGA1UEAxMd
'' SIG '' TWljcm9zb2Z0IFRpbWUtU3RhbXAgUENBIDIwMTACEzMA
'' SIG '' AAE+zsp3UsX3NCsAAAAAAT4wDQYJYIZIAWUDBAIBBQCg
'' SIG '' ggFKMBoGCSqGSIb3DQEJAzENBgsqhkiG9w0BCRABBDAv
'' SIG '' BgkqhkiG9w0BCQQxIgQgVJnlyzhOKXJQfE4PxVqyLV50
'' SIG '' G9jdw8nZGklZfDk+TswwgfoGCyqGSIb3DQEJEAIvMYHq
'' SIG '' MIHnMIHkMIG9BCCL686Nqo1O8o5ka63j0deuq3BSPZkK
'' SIG '' dU66sHB+BDGbEzCBmDCBgKR+MHwxCzAJBgNVBAYTAlVT
'' SIG '' MRMwEQYDVQQIEwpXYXNoaW5ndG9uMRAwDgYDVQQHEwdS
'' SIG '' ZWRtb25kMR4wHAYDVQQKExVNaWNyb3NvZnQgQ29ycG9y
'' SIG '' YXRpb24xJjAkBgNVBAMTHU1pY3Jvc29mdCBUaW1lLVN0
'' SIG '' YW1wIFBDQSAyMDEwAhMzAAABPs7Kd1LF9zQrAAAAAAE+
'' SIG '' MCIEIB8EFpwJcLo0G5bBKSx3B36OVdCMIWuA/CgdR27y
'' SIG '' vjL+MA0GCSqGSIb3DQEBCwUABIIBACjOob5ZQyfU4Vb0
'' SIG '' 60m904fnWxI74BngGrh3/jh78T8bU7xhKH+qbBmTuTaV
'' SIG '' K2iHMOKVeowCY/KsyvejUbki/iMhsMhUY814r/DI7qhu
'' SIG '' C+ZHU1Q41i9FR7GC26jJ6uEla8UYrwcGJs9USD6eqZOr
'' SIG '' zhkUnGuo5QmxpiS+Vo0FI8oEh4dpx427YoRtbX5reUGh
'' SIG '' qYjautfJc+/SuRBxYmRBz7kMYn6ul1sAKGGRybV/z84+
'' SIG '' Qln/Yo/IYNNMrlpxjPkop8JxsL3JIA7zNibsvQsHB+lQ
'' SIG '' IBe7y10knqDEuDTFsqQ+STcXZ6yMskD05tC6qSgi95aR
'' SIG '' tGi9e1VSn7a4+yfGPcM=
'' SIG '' End signature block

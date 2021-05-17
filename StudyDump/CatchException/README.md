# Dump

程序崩溃时记录dump，方便进行调试。

普通异常比较好抓dump，但是对于一些特殊的异常普通的方式抓不到。比如堆损坏异常，如果是重复释放还好办，因为是在重复释放的时候触发的。但是有时候在异常抛出前，堆栈早已被野指针写乱了。像这种普通的抓Dump的方式（调用`Kernel32.dll`中的`SetUnhandledExceptionFilter`)似乎不太管用了。即使抓到了也不是第一现场。

针对上述情况可以考虑配置Windows注册表，使应用程序在`Crash`时，操作系统自动生成Dump

## Windows Error Reporting

Crash dumps are very useful to debug an application. Recently, I worked on a Visual Studio extension we use in my company. It's very easy to develop such kind of application. However, there are lots of reasons for your extension to crash. Of course, you can add lots of try/catch, but you'll for sure forget the good one, so VS will crash. When it's happening, you would like to be able to attach a debugger and see the exception and the stack trace. Instead of attaching a debugger, you can automatically generate a crash dump that you can use to debug the application later.

In Windows, you can configure Windows Error Reporting (WER) to generate a dump when an application crashes.

1. Open `regedit.exe`
2. Open the key `HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\Windows Error Reporting\LocalDumps`
3. Set the value `DumpFolder` (REG_EXPAND_SZ) to the directory you want the dump to be created
4. Optionally, you can prevent WER to keep lots of crash dumps by setting `DumpCount` (DWORD) to a low number

Maybe you prefer to set the configuration using PowerShell:

```powershell
New-Item -Path "HKLM:\SOFTWARE\Microsoft\Windows\Windows Error Reporting" -Name "LocalDumps"
New-ItemProperty -Path "HKLM:\SOFTWARE\Microsoft\Windows\Windows Error Reporting\LocalDumps" -Name "DumpFolder" -Value "%LOCALAPPDATA%\CrashDumps" -PropertyType "ExpandString"
New-ItemProperty -Path "HKLM:\SOFTWARE\Microsoft\Windows\Windows Error Reporting\LocalDumps" -Name "DumpCount" -Value 10 -PropertyType DWord
```

You can also configure WER per application. So, if you want to generate a full dump only for one application, you can create a key for your application under `LocalDumps` with the configuration you want. If your application is `devenv.exe` the key name is `devenv.exe`. This is very simple!

## Reference

https://www.meziantou.net/tip-automatically-create-a-crash-dump-file-on-error.htm

https://docs.microsoft.com/en-us/windows/win32/wer/collecting-user-mode-dumps?redirectedfrom=MSDN
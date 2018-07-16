from cx_Freeze import setup, Executable

setup(name = "GUI",
      version = "2.1",
      description = "My GUI",
      executables = [Executable("Main_File.py", base = "Win32GUI")])

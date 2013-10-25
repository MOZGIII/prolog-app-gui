# Readme

## Requirements

To build this you'll need to have:

- Qt 4.8.x (libraries and compatible QtCreator)
- G++/MinGW 4.8+
- SWI-Prolog 6.5.2+ (but 6.4 should work too)

### Having `swipl` in `PATH` is required!

You have to be able to run `swipl` (and more specificly `swipl --dump-runtime-variables`) from the build shell.
The simplest way to achieve this is to add your SWI-Prolog's `.../bin` directory to `PATH`.
If you're on any GNU/Linux OS and installed swipl via the package manager everything should work out of the box, however on Windows you'll probably need to fix `PATH` manually (or you can alter `PATH` in Qt's build settings - this should work as well).


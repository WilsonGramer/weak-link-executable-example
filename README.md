# Weak-linking to an executable from a shared library (plugin architecture)

This repository demonstrates how to dynamically link to a "host" executable from a "plugin" shared library.

- `lib` — Contains a `greet` function accepting a string.

- `host` — "Host" executable that references `greet` in source and links to `lib` statically, providing the `greet` symbol in its executable binary.

- `plugin` — "Plugin" shared library that references `greet` in source but does not link to `lib` at all, leaving the `greet` symbol undefined at compile time. At runtime, `greet` will be accessible because `plugin` is loaded into `host`, gaining access to `host`'s symbols.

## Usage

Run `build.sh` to produce `host` and `plugin.dylib` in `bin/`. Run `host` and pass the path to the plugin as an argument:

```console
$ bin/host bin/plugin.dylib
Hello, world!
```

You can move the host and the plugin to arbitrary locations and it will still work. You can also change the strings used for the greeting, and mix and match hosts and plugins.

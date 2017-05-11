# prep

Read from stdin and prepend a string to each line while preserving
identation.

prep is a tool for prefixing blocks of text. It reads from stdin,
detects the indentation of the first line and proceeds to prepend
the passed prefix to each line. If the prefix argument is omited
it defaults to `#`. Lines containing only white space are preserved.

Installation
------------

Download the [latest release][releases] or check the available
[packages][packages]. You can also compile the source code in the
master branch.

[releases]: https://github.com/soveran/prep/releases
[packages]: https://github.com/soveran/prep/wiki/Distribution-Packages

Install prep into `/usr/local/bin` with the following command:

    $ make install

You can use `make PREFIX=/some/other/directory install` if you wish
to use a different destination. If you want to remove prep from
your system, use `make uninstall`.

### Examples

```
$ cat foo.cr
  def foo
    puts "foo"
  end

$ cat foo.cr | prep
  # def foo
  #   puts "foo"
  # end

$ cat foo.cr | prep --
  -- def foo
  --   puts "foo"
  -- end
```

If you use vis, you can select a block of text and run this command:

```
:|prep
```

You can also pass a string to use for the comment:

```
:|prep --
```

Usage is similar with vim:

```
:'<,'>!prep
```

As vim gives a special meaning to some characters, you may have to
escape them:

```
:'<,'>!prep \e%
```

Motivation
----------

Most text editors provide the means for creating plugins that comment
out text selections. That means tools similar to prep exist written
in Lua, VimL, Emacs Lisp, etc. As it's often the case, once a person
chooses a text editor they will stick to it for a long time, so
once they have found a suitable plugin for commenting code there's
no need to look for alternatives.

In my case, I switched from vim to vis, and like many other editors
with vis I can replace some text range with the result of piping
it to an external tool. The scripting language for vis is Lua, so
I could have written this tool as a plugin. Instead, I thought about
creating a specialized tool that can eventually be used from other
editors or even from scripts. Also, even though we call the feature
"commenting", it's just prepending a string while preserving the
indentation. That means it has potential to cover other use cases.

Contributing
------------

If you find a bug, please create an issue detailing the ways to
reproduce it. If you have a suggestion, create an issue detailing
the use case.

1x4 Macropad With Encoder
=========

This is a build of a 1x4 Macropad with an ecoder using a Arduino Pro Micro and QMK Firmware 

![alt text](https://github.com/DIYCharles/DIYKeyboards-/blob/master/photos/img1.jpg "img1.jpg")

Table of contents
=================

<!--ts-->
   * [Wiring](#Wiring)
   * [Build](#Build)
   * [QMK Firmware](#QMK-Firmware)
   * [Compile And Flash](#Compile-And-Flash)
<!--te-->


Wiring
============

I wired this in the COL2ROW diode configuration

![alt text](https://github.com/DIYCharles/DIYKeyboards-/blob/master/photos/img3.jpg "img3.jpg")

![alt text](https://github.com/DIYCharles/DIYKeyboards-/blob/master/photos/img4.jpg "img4.jpg")






Installation
============

Linux (manual installation)
```bash
$ wget https://raw.githubusercontent.com/ekalinin/github-markdown-toc/master/gh-md-toc
$ chmod a+x gh-md-toc
```

macOS (manual installation)
```bash
$ curl https://raw.githubusercontent.com/ekalinin/github-markdown-toc/master/gh-md-toc -o gh-md-toc
$ chmod a+x gh-md-toc
```

Linux or macOS (using [Basher](https://github.com/basherpm/basher))
```bash
$ basher install ekalinin/github-markdown-toc
# `gh-md-toc` will automatically be available in the PATH
```

Usage
=====


STDIN
-----

Here's an example of TOC creating for markdown from STDIN:

```bash
➥ cat ~/projects/Dockerfile.vim/README.md | ./gh-md-toc -
  * [Dockerfile.vim](#dockerfilevim)
  * [Screenshot](#screenshot)
  * [Installation](#installation)
        * [OR using Pathogen:](#or-using-pathogen)
        * [OR using Vundle:](#or-using-vundle)
  * [License](#license)
```

Local files
-----------

Here's an example of TOC creating for a local README.md:

```bash
➥ ./gh-md-toc ~/projects/Dockerfile.vim/README.md


Table of Contents
=================

  * [Dockerfile.vim](#dockerfilevim)
  * [Screenshot](#screenshot)
  * [Installation](#installation)
        * [OR using Pathogen:](#or-using-pathogen)
        * [OR using Vundle:](#or-using-vundle)
  * [License](#license)
```

Remote files
------------

And here's an example, when you have a README.md like this:

  * [README.md without TOC](https://github.com/ekalinin/envirius/blob/f939d3b6882bfb6ecb28ef7b6e62862f934ba945/README.md)

And you want to generate TOC for it.

There is nothing easier:

```bash
➥ ./gh-md-toc https://github.com/ekalinin/envirius/blob/master/README.md

Table of Contents
=================

  * [envirius](#envirius)
    * [Idea](#idea)
    * [Features](#features)
  * [Installation](#installation)
  * [Uninstallation](#uninstallation)
  * [Available plugins](#available-plugins)
  * [Usage](#usage)
    * [Check available plugins](#check-available-plugins)
    * [Check available versions for each plugin](#check-available-versions-for-each-plugin)
    * [Create an environment](#create-an-environment)
    * [Activate/deactivate environment](#activatedeactivate-environment)
      * [Activating in a new shell](#activating-in-a-new-shell)
      * [Activating in the same shell](#activating-in-the-same-shell)
    * [Get list of environments](#get-list-of-environments)
    * [Get current activated environment](#get-current-activated-environment)
    * [Do something in environment without enabling it](#do-something-in-environment-without-enabling-it)
    * [Get help](#get-help)
    * [Get help for a command](#get-help-for-a-command)
  * [How to add a plugin?](#how-to-add-a-plugin)
    * [Mandatory elements](#mandatory-elements)
      * [plug_list_versions](#plug_list_versions)
      * [plug_url_for_download](#plug_url_for_download)
      * [plug_build](#plug_build)
    * [Optional elements](#optional-elements)
      * [Variables](#variables)
      * [Functions](#functions)
    * [Examples](#examples)
  * [Example of the usage](#example-of-the-usage)
  * [Dependencies](#dependencies)
  * [Supported OS](#supported-os)
  * [Tests](#tests)
  * [Version History](#version-history)
  * [License](#license)
  * [README in another language](#readme-in-another-language)
```

That's all! Now all you need — is copy/paste result from console into original
README.md.

If you do not want to copy from console you can add `> YOURFILENAME.md` at the end of the command like `./gh-md-toc https://github.com/ekalinin/envirius/blob/master/README.md > table-of-contents.md` and this will store the table of contents to a file named table-of-contents.md in your current folder.

And here is a result:

  * [README.md with TOC](https://github.com/ekalinin/envirius/blob/24ea3be0d3cc03f4235fa4879bb33dc122d0ae29/README.md)

Moreover, it's able to work with GitHub's wiki pages:

```bash
➥ ./gh-md-toc https://github.com/ekalinin/nodeenv/wiki/Who-Uses-Nodeenv

Table of Contents
=================

  * [Who Uses Nodeenv?](#who-uses-nodeenv)
    * [OpenStack](#openstack)
    * [pre-commit.com](#pre-commitcom)
```

Multiple files
--------------

It supports multiple files as well:

```bash
➥ ./gh-md-toc \
    https://github.com/aminb/rust-for-c/blob/master/hello_world/README.md \
    https://github.com/aminb/rust-for-c/blob/master/control_flow/README.md \
    https://github.com/aminb/rust-for-c/blob/master/primitive_types_and_operators/README.md \
    https://github.com/aminb/rust-for-c/blob/master/unique_pointers/README.md

  * [Hello world](https://github.com/aminb/rust-for-c/blob/master/hello_world/README.md#hello-world)

  * [Control Flow](https://github.com/aminb/rust-for-c/blob/master/control_flow/README.md#control-flow)
    * [If](https://github.com/aminb/rust-for-c/blob/master/control_flow/README.md#if)
    * [Loops](https://github.com/aminb/rust-for-c/blob/master/control_flow/README.md#loops)
    * [For loops](https://github.com/aminb/rust-for-c/blob/master/control_flow/README.md#for-loops)
    * [Switch/Match](https://github.com/aminb/rust-for-c/blob/master/control_flow/README.md#switchmatch)
    * [Method call](https://github.com/aminb/rust-for-c/blob/master/control_flow/README.md#method-call)

  * [Primitive Types and Operators](https://github.com/aminb/rust-for-c/blob/master/primitive_types_and_operators/README.md#primitive-types-and-operators)

  * [Unique Pointers](https://github.com/aminb/rust-for-c/blob/master/unique_pointers/README.md#unique-pointers)
```

Combo
-----

You can easily combine both ways:

```bash
➥ ./gh-md-toc \
    ~/projects/Dockerfile.vim/README.md \
    https://github.com/ekalinin/sitemap.s/blob/master/README.md

  * [Dockerfile.vim](~/projects/Dockerfile.vim/README.md#dockerfilevim)
  * [Screenshot](~/projects/Dockerfile.vim/README.md#screenshot)
  * [Installation](~/projects/Dockerfile.vim/README.md#installation)
        * [OR using Pathogen:](~/projects/Dockerfile.vim/README.md#or-using-pathogen)
        * [OR using Vundle:](~/projects/Dockerfile.vim/README.md#or-using-vundle)
  * [License](~/projects/Dockerfile.vim/README.md#license)

  * [sitemap.js](https://github.com/ekalinin/sitemap.js/blob/master/README.md#sitemapjs)
    * [Installation](https://github.com/ekalinin/sitemap.js/blob/master/README.md#installation)
    * [Usage](https://github.com/ekalinin/sitemap.js/blob/master/README.md#usage)
    * [License](https://github.com/ekalinin/sitemap.js/blob/master/README.md#license)

Created by [gh-md-toc](https://github.com/ekalinin/github-markdown-toc)
```

Auto insert and update TOC
--------------------------

Just put into a file these two lines:

```
<!--ts-->
<!--te-->
```

And run:

```bash
$ ./gh-md-toc --insert README.test.md

Table of Contents
=================

   * [gh-md-toc](#gh-md-toc)
   * [Installation](#installation)
   * [Usage](#usage)
      * [STDIN](#stdin)
      * [Local files](#local-files)
      * [Remote files](#remote-files)
      * [Multiple files](#multiple-files)
      * [Combo](#combo)
   * [Tests](#tests)
   * [Dependency](#dependency)

!! TOC was added into: 'README.test.md'
!! Origin version of the file: 'README.test.md.orig.2018-02-04_192655'
!! TOC added into a separate file: 'README.test.md.toc.2018-02-04_192655'


Created by [gh-md-toc](https://github.com/ekalinin/github-markdown-toc)
```

Now check the same file:

```bash
➜ grep -A15 "<\!\-\-ts" README.test.md
<!--ts-->
   * [gh-md-toc](#gh-md-toc)
   * [Table of contents](#table-of-contents)
   * [Installation](#installation)
   * [Usage](#usage)
      * [STDIN](#stdin)
      * [Local files](#local-files)
      * [Remote files](#remote-files)
      * [Multiple files](#multiple-files)
      * [Combo](#combo)
      * [Auto insert and update TOC](#auto-insert-and-update-toc)
   * [Tests](#tests)
   * [Dependency](#dependency)

<!-- Added by: <your-user>, at: 2018-02-04T19:38+03:00 -->

<!--te-->
```

Next time when your file will be changed just repeat the command (`./gh-md-toc
--insert ...`) and TOC will be refreshed again.

GitHub token
------------

All your tokens are [here](https://github.com/settings/tokens).

You will need them if you get an error like this:

```
Parsing local markdown file requires access to github API
Error: You exceeded the hourly limit. See: https://developer.github.com/v3/#rate-limiting
or place github auth token here: ./token.txt
```

A token can be used as an env variable:

```bash
➥ GH_TOC_TOKEN=2a2dab...563 ./gh-md-toc README.md

Table of Contents
=================

* [github\-markdown\-toc](#github-markdown-toc)
* [Table of Contents](#table-of-contents)
* [Installation](#installation)
* [Tests](#tests)
* [Usage](#usage)
* [LICENSE](#license)
```

Or from a file:

```bash
➥ echo "2a2dab...563" > ./token.txt
➥ ./gh-md-toc README.md

Table of Contents
=================

* [github\-markdown\-toc](#github-markdown-toc)
* [Table of Contents](#table-of-contents)
* [Installation](#installation)
* [Tests](#tests)
* [Usage](#usage)
* [LICENSE](#license)
```

Tests
=====

Done with [bats](https://github.com/sstephenson/bats).
Useful articles:

  * https://blog.engineyard.com/2014/bats-test-command-line-tools
  * http://blog.spike.cx/post/60548255435/testing-bash-scripts-with-bats


How to run tests:

```bash
➥ make test                                                                                                                 

 ✓ TOC for local README.md
 ✓ TOC for remote README.md
 ✓ TOC for mixed README.md (remote/local)
 ✓ TOC for markdown from stdin
 ✓ --help
 ✓ --version

6 tests, 0 failures
```

Dependency
==========

  * curl or wget
  * awk (mawk is not tested)
  * grep
  * sed
  * bats (for unit tests)

Tested on Ubuntu 14.04/14.10 in bash/zsh.

Docker
==========

* Build

```shell
docker build -t markdown-toc-generator .
```

* Run on an URL

```shell
docker run -it markdown-toc-generator https://github.com/ekalinin/envirius/blob/master/README.md
```

* Run on a local file (need to share volume with docker)

```shell
docker run -it -v /data/ekalinin/envirius:/data markdown-toc-generator /data/README.md
```




# 1x4 Macropad With Encoder

Very simple and easy to understand code to make your own custom macropad. Each key switch requires its own pin on the pro micro. This is not the optimal configuration but make it very easy to use. 

Please ignore the photos in the pics folder I have changed the wiring. I have each key switch connected on one pin to the common ground and the other pin is directly connected to it's own pin. This limits the number of switches you can add to the circuit to the number of pins on your board instead of using a switch matrix.

Currently the code does not support the encoders.
![alt text](https://i.imgur.com/JUtJT0c.jpg "4x4")


# Setup

## Wiring 
To wire up a key connect one of the pins of the momentary switch to ground and the other pin to a digital pin 2-21. The switch will activate the key when the pin is shorted to ground then it will delay so that the key is not input more times than desired.

## Program Pro Micro
To program click the verify and upload then quickly enter bootloader mode. If you don't do it fast enough it will not connect.

## Enter Bootloader Mode 
To enter bootloader mode on the pro micro short the rst pin to the ground pin twice quickly. This will keep it in bootloader mode for 8s.

# Microsoft Teams Shortcut keys
Accept video call    Ctrl+Shift+A

Accept audio call    Ctrl+Shift+S

Decline     call Ctrl+Shift+D

Start audio call     Ctrl+Shift+C

Start video call     Ctrl+Shift+U

Toggle mute  Ctrl+Shift+M

Toggle video    Ctrl+Shift+O

Go to sharing toolbar   Ctrl+Shift+Space

https://support.office.com/en-us/article/keyboard-shortcuts-for-microsoft-teams-2e8e2a70-e8d8-4a19-949b-4c36dd5292d2


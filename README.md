# CuteRest
CuteRest is a REST client tool dedicated for JSON... and also for XML. 
Website avaible at http://dridk.github.io/cuterest/

![CuteRest under linux](https://raw.githubusercontent.com/dridk/cuterest/master/screenshot.png "cuterest")

## What is CuteRest
CuteRest is an open source tool dedicated to communicate with a REST server. It's particulary useful to manage 
JSON request during developement phase. Actually, there are several tools for this purpose. You can use plugins for
your browser, like [Postman](https://chrome.google.com/webstore/detail/postman-rest-client/fdmmgilgnpjigdojojpjoooidkmcomcm) or use [httpie](https://github.com/jakubroztocil/httpie) as command-line from your console. But those applications do not provide
a tree view of the JSON or XML response. You only have raw data, and you must use another software, like 
[jsonviewer](http://jsonviewer.stack.hu/) to view your content as a tree.  
CuteRest does have both. It's a REST client which have different view to parse the response.

### Features

* HTTP verbs supported: `GET`, `POST`, `PUT`, `DELETE`, `HEAD`, `PATCH`, `OPTION`
* View as JSON Tree
* View as XML Tree 
* HTML Web rendering
* JSON syntax highlighting
* XML syntax highlighting
* Search by key or value inside the tree
* Authentication: Basic, NTLM version 2 and Digest-MD5 
* Proxy settings
* View request history
* Save request to favorites
* Import & Export favorites

## Windows
Windows binaries can be downloaded from here:
[CuteRest-win32-beta-0.1.exe](https://github.com/dridk/cuterest/releases/download/v0.1-beta/CuteRest-win32-beta-0.1.exe)

## MacOS X
Mac OS binaries can be downloaded from here:
[CuteRest-beta-0.1.dmg](https://github.com/dridk/cuterest/releases/download/v0.1-beta/CuteRest-beta-0.1.dmg)

## Linux
CuteRest works well on Linux. There aren't packages avaible for any distribution yet. I will publish a Debian package
as soon as possible. For now, you'll need to compile it as described below. 

## From source
Compiling on Windows, OSX, Linux, and FreeBSD is really easy. But CuteRest needs at least Qt5.4. Older version will generate complaints during the compilation. 
* Download the community Qt 5.4 SDK from [qt.io](http://www.qt.io/download/).
* Download the source code from `master` branch. 
* From Qt Creator, File > Open project, then select `cuterest.pro`.
* Compile and run it by clicking on the green button.

If you want to install it on your system, compile and install it from the command line by using `qmake` in your Qt installation path. 
    
    qmake cuterest.pro
    make
    sudo make install

## Twitter

Follow me on Twitter: https://twitter.com/dridk

## Releases

* [Version beta 0.1 released](https://github.com/dridk/cuterest/releases/tag/v0.1-beta) - 2015-04-06

## Author

* Schutz alias [@dridk](https://github.com/dridk) Created all the Qt code
* Eugene Trounev alias [@its](https://github.com/its) Helped with the design
* Lucas Bourneuf alias [@Aluriak](https://github.com/its) Helped with the JSON tree model 

## License

CuteRest is licensed under the GNU General Public License Version 3 or later.


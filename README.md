Web based interface for face detection with OpenCV
==================================================

A sample project for demonstrating web-based GUI for OpenCV. This project using web technologies (HTML5, Javascript, PHP) for the frontend of my face detection program.

Project page: http://goo.gl/jI4xA  
Video demo: http://youtube.com/watch?v=0ZDQ7ZH76i0

## Requirements

1. Apache web server
2. PHP 5.3 or above
3. OpenCV 2.4.3 or above
4. HTML5 enabled web browser (Google Chrome is recommended)

## Installation

1. First you need to compile `face-detect/face-detect.cpp`.  
<pre>g++ \`pkg-config --cflags --libs opencv\` face-detect.cpp -o face-detect</pre>
1. Create a directory in your htdocs, e.g: `web-face-detect` and copy all files into the directory.
1. Start your web server.
1. Open `http://localhost/web-face-detect` with your browser.
1. Try the sample images in `assets/img/`.


## Image credits

The sample images in `assets/img/` are Creative Commons licensed.

* 1.jpg - [Wikimedia Commons](http://commons.wikimedia.org/wiki/File:Peter_Scott-Morgan_\(seated\)_as_Chairman_of_BCS_Robotics_Committee_in_1983.jpg)
* 2.jpg - [Flickr](http://www.flickr.com/photos/dougneiner/4555211967)
* 3.jpg - [Flickr](http://www.flickr.com/photos/dougneiner/4555181685)
* 4.jpg - [Flickr](http://www.flickr.com/photos/rj3/5640465919)


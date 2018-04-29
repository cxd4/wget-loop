# wget-loop
Simple program to automate number-range file downloads on GNU systems.

## Syntax
```sh
wgetloop [prefix] [suffix] [count] [start]
```

Only the last parameter, `start`, is optional.  In the absence of its specification, the starting file number will be 0.

## Examples
```sh
# Download all files from image-0.jpg to image-999.jpg.
wgetloop http://www.example.com/image- .jpg 1000 0
wgetloop http://www.example.com/image- .jpg 1000 # last param optional

# Download all files from image-000.jpg to image-999.jpg.  (Note the leading zeroes.)
wgetloop http://www.example.com/image- .jpg 1000 000 # not "0", "000"

# Download file.jpg from domains image-000.com to image-999.com.
wgetloop http://www.image- .com/file.jpg 1000 000
```

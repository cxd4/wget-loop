# wget-loop
Simple program to automate number-range file downloads on GNU systems.

## Syntax
```sh
wgetloop [prefix] [suffix] [end] [start]
```

Only the last parameter, `start`, is optional.  In the absence of its specification, the starting file number will be 0, padded with enough zeroes to fit the number of digits that defines `end`.

## Examples
```sh
# Download all files from image-000.jpg to image-999.jpg.
wgetloop http://www.example.com/image- .jpg 999 000
wgetloop http://www.example.com/image- .jpg 999 # last param optional

# Download all files from image-0.jpg to image-999.jpg.  (Note the leading zeroes.)
wgetloop http://www.example.com/image- .jpg 999 0 # not "000", "0"

# Download file.jpg from domains image-001.com to image-999.com.
wgetloop http://www.image- .com/file.jpg 999 001
```

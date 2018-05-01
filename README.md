# wget-loop
Simple program to automate number-range file downloads on GNU systems.

## Syntax
```sh
wgetloop [prefix] [suffix] [start] [final]
wgetloop [prefix] [suffix] [final] [start]
wgetloop [prefix] [suffix] [count]
```

The third variant is identical to the second variant, with a value of 0 (padded with leading zeroes to fit the digit count for `count`) assumed for the unspecified `start` parameter.

## Examples
```sh
# Download all files from image-000.jpg to image-999.jpg.
wgetloop http://www.example.com/image- .jpg 000 999
wgetloop http://www.example.com/image- .jpg 999 000 # same difference, literally
wgetloop http://www.example.com/image- .jpg 999 # last param optional

# Download all files from image-0.jpg to image-999.jpg (no leading zeroes).
wgetloop http://www.example.com/image- .jpg 999 0 # forces "0" over "000"

# Download file.jpg from domains image-001.com to image-999.com.
wgetloop http://www.image- .com/file.jpg 999 001
```

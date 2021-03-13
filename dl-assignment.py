#!./venv/bin/python

from markdownify import markdownify
import requests
import sys
import re

[py_file, series_number] = sys.argv

# example: https://unifr.coursc.ch/1/content.html
link = f"https://unifr.coursc.ch/{series_number}/content.html"
print(f"Requesting: {link}", file=sys.stderr)
page = requests.get(link)

if page.status_code / 100 != 2:
    print(page.status_code, file=sys.stderr)
    print(markdownify(page.content), file=sys.stderr)
    exit(1)


md = markdownify(page.content)
# replace link not starting with a character [a-z] (either protocol or domain)
# like root relative reference or hash, prefix with the base url
md = re.sub(r"]\(([^a-z])", r"](https://unifr.coursc.ch/\1", md)


print(md)
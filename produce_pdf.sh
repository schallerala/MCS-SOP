#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"


entry_file=$1
out_pdf="${entry_file%.*}.pdf"


# Geometry: https://stackoverflow.com/a/13516042/3771148
# Listings: https://tex.stackexchange.com/a/179956/164820
pandoc -o "$out_pdf" -V geometry:margin=0.6in --listings -H "$DIR"/listings-setup.tex "$entry_file"

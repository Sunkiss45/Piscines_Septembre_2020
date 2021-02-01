#!/bin/bash
cat /etc/passwd | sed '/^#/d' | sed 's/:.*//' | awk 'NR % 2 == 0' | rev | sort -r | sed -n "$FT_LINE1, $FT_LINE2 p" | tr "\n" ',' | sed 's/,/, /g' | rev | sed 's/ ,/./' | rev | tr -d "\n"

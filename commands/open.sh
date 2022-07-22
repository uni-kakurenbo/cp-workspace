#! /bin/bash

CALLED="$PWD"

if [ $# -lt 1 ]; then
  echo "At least a arguments are required:"
  echo "1. File Name"
  echo "[2.] Extension (Default: .cpp)"
  exit 0
fi

FILE="$1"
FILENAME_WITHOUT_EXT="${FILE%.*}"
EXTNAME="${FILE##*.}"
if [ "$FILENAME_WITHOUT_EXT" == "$EXTNAME" ]; then
  if [ "$2" == "" ]; then
    PREV=$(find . -iname "$1*")
    if [ "$PREV" != "" ]; then
      # shellcheck disable=2116,2086
      echo "$(tput setaf 6)INFO: $(tput sgr0)Some files were found that already exist:$(tput setaf 5) $(echo $PREV)"
      echo "$(tput setaf 2)INFO: $(tput sgr0)Open them."
      for file in $PREV; do
        code "$file"
      done
      exit 0
    fi
    EXTNAME=cpp
  else
    EXTNAME=$2
  fi
  FILE+=.$EXTNAME
fi

FOUND=$(find . -iname "$FILE")
if [ "$FOUND" == "" ]; then
  echo "$(tput setaf 6)INFO: $(tput sgr0)Could not find the file."
  echo "$(tput setaf 10)INFO: $(tput sgr0)Do you want to create a new file? (y/n)"
  read -p "$(tput setaf 8)>> $(tput sgr0)" -r input
  if ! { [ "$input" == "y" ] || [ "$input" == "yes" ] || [ "$input" == "YES" ]; }; then
    exit 0
  fi
else
  for FILE in $FOUND; do
    break
  done
  echo "$(tput setaf 6)INFO: $(tput sgr0)The file was found that already exist:$(tput setaf 5) $FILE"
  code "$FILE"
  exit 0
fi

cd "$(dirname "$0")" || exit 1
source cp.env

cd "$ROOT" || exit 1

touch "./templates/template.$EXTNAME"
TEMPLATE=$(readlink -f "./templates/template.$EXTNAME")

cd "$CALLED" || exit 1

echo "$(tput setaf 2)INFO: $(tput sgr0)Create a new file and open it: $(tput setaf 5)$FILE"
cp -n "$TEMPLATE" "./$FILE"
code "$FILE"

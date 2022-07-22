#!/bin/bash

CALLED="$PWD"

ARGUMENTS=("$0")
while (($# > 0)); do
  case "$1" in
  -c | --contest)
    CONTEST_ID="$2"
    shift
    ;;
  -*)
    echo "$(tput setaf 1)ERROR: $(tput sgr0)Unexpected command option: $(tput setaf 5)$1"
    exit 1
    ;;
  *)
    ARGUMENTS=("${ARGUMENTS[@]}" "$1")
    ;;
  esac
  shift
done

if ! [ "$CONTEST_ID" ]; then
  CONTEST_ID=$(basename "$CALLED")
fi
PROBLEM_ID="${ARGUMENTS[1]}"

cd "$(dirname "${ARGUMENTS[0]}")" || exit 1
source cp.env

source ./core/functions/isUseable.sh

isUseable "$CALLED"
FIRST="$?"
isUseable "$(dirname "$CALLED")"
SECOND="$?"

URL=""

if [ "$FIRST" == "0" ] || [ "$SECOND" == "0" ]; then
  URL="https://atcoder.jp/contests/$CONTEST_ID"
else
  echo "$(tput setaf 3)WARN: $(tput sgr0)This command cannot be used in the directory."
  exit 1
fi

if [ "$SECOND" == "0" ] && [ "$PROBLEM_ID" != "" ]; then
  URL+="/tasks/${CONTEST_ID}_$PROBLEM_ID"
fi

echo "Oepn: $(tput setaf 6)$URL"
"$CHROME_PATH" "$URL"

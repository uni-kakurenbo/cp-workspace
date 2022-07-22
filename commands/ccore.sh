#!/bin/bash

cd "$(dirname "$0")" || exit 1
source cp.env

cd "$ROOT" || exit 1
cd ./commands/core || exit 1

subcommand="$1"
shift

case $subcommand in
build_cpp)
  RESPONSE="$(./build_cpp.sh "$@")"
  ;;
select-dir)
  RESPONSE="$(./select-dir.sh "$@")"
  ;;
sample)
  RESPONSE="$(node ./scrape-sample-cases.js "$@")"
  ;;
esac
echo "$RESPONSE"

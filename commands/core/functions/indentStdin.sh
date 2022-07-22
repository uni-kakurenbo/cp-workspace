#! /bin/bash

indentStdin() {
  while IFS= read -r line; do
    echo "$1""${line}"
  done
}

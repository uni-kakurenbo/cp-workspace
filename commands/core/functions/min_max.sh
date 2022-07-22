#! /bin/bash

function min() {
  echo "if($1 < $2) $1 else $2" | bc
  return 0
}

function max() {
  echo "if($1 > $2) $1 else $2" | bc
  return 0
}

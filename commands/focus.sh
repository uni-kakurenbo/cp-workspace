#! /bin/bash
CALLED="$PWD"

SELECTED_COUNTEST="$1$2$3"

if [ $# -lt 1 ]; then
  echo "At least a arguments are required:"
  echo "1. ContestId"
  exit 0
fi

DIRECTORY=$(ccore select-dir "$CALLED")
if [ "$DIRECTORY" == 1 ]; then
  echo "$(tput setaf 3)WARN: $(tput sgr0)This command cannot be used in the directory."
  return 1
fi
echo "$(tput setaf 6)INFO: $(tput sgr0)Contest selected: $(tput setaf 5)$SELECTED_COUNTEST"

FOUND=$(find "$DIRECTORY" -iname "$SELECTED_COUNTEST")
if [ "$FOUND" == "" ]; then
  echo "$(tput setaf 6)INFO: $(tput sgr0)Could not find the directory."
  echo "$(tput setaf 10)INFO: $(tput sgr0)Do you want to create a new directory? (y/n)"
  read -p "$(tput setaf 8)>> $(tput sgr0)" -r input
  if [ "$input" == "y" ] || [ "$input" == "yes" ] || [ "$input" == "YES" ]; then
    DIRECTORY="${DIRECTORY}/$SELECTED_COUNTEST"
    mkdir "${DIRECTORY}"
    FOUND="$DIRECTORY"
  else
    return 0
  fi
else
  echo "$(tput setaf 6)INFO: $(tput sgr0)The directory is already exists."
fi

echo "$(tput setaf 4)INFO: $(tput sgr0)Move to $(tput setaf 5)$FOUND"
cd "$FOUND" || exit 1

#! /bin/bash

# checks to see if we are in a windows or linux dir
function isWinDir {
    case $PWD/ in
    /mnt/*) return $(true) ;;
    *) return $(false) ;;
    esac
}

# wrap the git command to either run windows git or linux
function git {
    if isWinDir; then
        git.exe "$@"
    else
        /usr/bin/git "$@"
    fi
}

# shellcheck source=/dev/null
. "$HOME/CompetitiveProgramming/secrets.sh"

export CPLUS_INCLUDE_PATH="$HOME/CompetitiveProgramming/sources/libraries/ac-library"

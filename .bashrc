#! /bin/bash

function _update_ps1() {
    PS1="$(~/.local/bin/powerline-shell $?)"
}

if [ "$TERM" != "linux" ]; then
    PROMPT_COMMAND="_update_ps1; $PROMPT_COMMAND"
fi

export USE_CCACHE=1
export CCACHE_DIR=/root/.ccache

alias colors="~/.local/lib/256-colors.sh"

alias ccore="~/CompetitiveProgramming/commands/ccore.sh"

alias slc="source ~/CompetitiveProgramming/commands/focus.sh"
alias abc="slc abc"
alias arc="slc arc"
alias agc="slc agc"
alias ahc="slc ahc"

alias op="~/CompetitiveProgramming/commands/open.sh"
alias fd="~/CompetitiveProgramming/commands/find.sh"

alias jp="~/CompetitiveProgramming/commands/jump.sh"

alias ts="~/CompetitiveProgramming/commands/test.sh"

alias sub="~/CompetitiveProgramming/commands/submit.sh"
alias clp="~/CompetitiveProgramming/commands/clip.sh"

alias pre-compile="~/CompetitiveProgramming/commands/pre-compile.sh"

. "$HOME/.cargo/env"

export NVM_DIR="$HOME/.nvm"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"  # This loads nvm
[ -s "$NVM_DIR/bash_completion" ] && \. "$NVM_DIR/bash_completion"  # This loads nvm bash_completion

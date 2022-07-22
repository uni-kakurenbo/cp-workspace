function main([[]]) {
}

const stdin = require("fs").readFileSync("/dev/stdin", "utf8");
const input = stdin.trim().split("\n").map(i=>i.trim().split(/\s+/).map(i=>isNaN(i)?i:i-0))
main(input);

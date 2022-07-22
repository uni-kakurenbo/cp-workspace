function Main(_inputStr) {
  const input = _inputStr
    .trim().split("\n")
    .map(_row => {
      return _row.trim().split(/\s+/)
        .map(_item => {const _num = Number(_item); return isNaN(_num) ? _item : _num})
    })
  //console.log(input)
  let [[X]] = input;
  if(X < 40) return console.log(40 - X)
  if(X < 70) return console.log(70- X)
  if(X < 90) return console.log(90 - X)
  console.log("expert")
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));

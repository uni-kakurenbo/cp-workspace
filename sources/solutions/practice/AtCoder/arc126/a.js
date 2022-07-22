// inputに入力データ全体が入る
function Main(_inputStr) {
  const input = _inputStr
    .trim().split("\n")
    .map(_row => {
      return _row.trim().split(/\s+/)
        .map(_item => {const _num = Number(_item); return isNaN(_num) ? _item : _num})
    })
  //console.log(input)
  let [[T], ...Cases] = input;
  //console.log(Cases)
  conds = [[0,2,1],[1,0,2],[2,2,0],[3,0,1],[5,0,0]]
  for(let _case of Cases) {
    let ans = 0;
    let f = true;
    while(f) {
      //console.log(_case)
      f = conds.filter(_cond => {
        //console.log(_case)
        if(_case[0] >= _cond[0] && _case[1] >= _cond[1] && _case[2] >= _cond[2]) {
          const d = [];
          for(let i = 0; i <= 2; i++) if(_cond[i] !== 0) d.push(Math.floor(_case[i]/_cond[i]));
          const w = Math.min(...d)
          //console.log(w)
          for(let i = 0; i <= 2; i++) _case[i] -= _cond[i] * w;
          ans += w;
          return true;
        } else {
          return false;
        }
      }).length > 0;
    }
  console.log(ans)
  }
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));

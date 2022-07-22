const Main = function(input){
function r(input){
var str = new String(input);
var out = "";
 for(var i = str.length; i > 0 ; i--){
   out += str.charAt(i - 1);
 }
return out;
};
S = new String(input.split("\n")[0]);
var n = S.length;
if(r(S) == S){
  var b = S.substring(-1,(n-1)/2);
  if(r(b) == b){
    var c = S.substring((n+3)/2-1,n);
    if(r(c) == c){
      console.log("Yes");
    }else{console.log("No");}
  }else{console.log("No");}
}else{console.log("No");}
};
Main(require("fs").readFileSync("/dev/stdin", "utf8"));

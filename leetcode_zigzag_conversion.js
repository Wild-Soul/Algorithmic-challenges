/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
    let ans = new Array(numRows);
        for(let i=0; i<numRows; i++) ans[i]="";
        let j=0;
        let flag = true;
        for(let i=0; i<s.length; i++) {
            ans[j] +=s[i];
            if(flag) {
                if(j==numRows-1) {
                    j = Math.max(j-1,0);
                    flag = false;
                } else {
                    j = Math.min(j+1,numRows-1);
                }
            } else {
                if(j==0) {
                    j = Math.min(j+1,numRows-1);
                    flag = true;
                } else {
                    j = Math.max(j-1,0);
                }
            }
        }
    var tmp = "";
    for(j=0; j<numRows; j++) {
        tmp = tmp + ans[j];
    }
    return tmp;
};


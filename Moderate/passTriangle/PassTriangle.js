var fs  = require("fs");
var lines=[];
fs.readFileSync(process.argv[2]).toString().split('\n').forEach(function (line) {
    if (line != "") {
        var nums=line.split(" ");
        lines.push(nums);
    }
});

for(var y=lines.length-1;y>0;y--){
	for(var x=0;x<lines[y].length-1;x++){
		lines[y-1][x] = parseInt(lines[y-1][x])+parseInt(lines[y][x] > lines[y][x+1] ? lines[y][x] : lines[y][x+1]); 
	}
}
console.log(lines[0][0]);

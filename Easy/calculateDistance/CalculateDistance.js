var fs  = require("fs");
function Point(x,y){
	this.x=x;
	this.y=y;
}
fs.readFileSync(process.argv[2]).toString().split('\n').forEach(function (line) {
    if (line != "") {
    	var points=processLine(line);
    	console.log(getDistance(points[0],points[1]));
    }
});

function processLine(line){
	var points=[];
	line=line.substr(1,line.length-2);
		line.split(") (").forEach(function (coord){
			var coords=coord.split(", ");
			points.push(new Point(coords[0],coords[1]));
		});
	return points;
}
function getDistance(p1,p2){
	var dX=Math.pow(p1.x-p2.x,2);
	var dY=Math.pow(p1.y-p2.y,2);
	var dist=Math.sqrt(dX+dY);
	return parseInt(dist);
}

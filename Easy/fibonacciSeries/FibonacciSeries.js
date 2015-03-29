var fs  = require("fs");
fs.readFileSync(process.argv[2]).toString().split('\n').forEach(function (line) {
    if (line != "") {
    	var limit=parseInt(line);
	    var b=0,c=0,a=1;
			for(var i=0;i<limit;i++){
				c=a+b;
				b=a;
				a=c;
			}
			console.log(b);
    }
});

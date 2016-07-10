for (var y = 1; y <= 12; y++) {
  var line = "";
  for (var x = 1; x <= 12; x++) {
    var result = "";
    result += y * x;
    line += "   ".substr(0, 4 - result.length) + result;
  }
  console.log(line);
}

var http = require("http");
const Max = require("max-api");
const express = require("express");
const app = express();

var bodyParser 	= require("body-parser");
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({
    extended: true
}));

function anypost(str) {
	if (Max) {
		Max.post(str);
	} else {
		console.log(str);
	}
}

app.post("/fromDevice", function (req, res) {
	let responseText = "";
    console.log(res.req.body);
    Max.outlet(res.req.body);
    res.status(200).json({ error: 'something is wrong' });
});

app.listen(3000, function () {
	anypost("Example app listening on port 3000!");
	if (Max) Max.outlet("ready");
});
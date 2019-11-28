const http = require("http");
const express = require("express");
const port = 3000;
const ip = 'localhost';
const app = express();


http.createServer(app).listen(port, () => {
    console.log("Servidor rodando na porta " +  `${port}`);
})

app.get("/", function(req, res){
    res.send("<h1>Servidor");
})

app.post("/msg", function(req, res) {
    var body = '';
    req.on('data', function (data) {
        body += data;
    });

    req.on('end', function (data) {
        console.log(body);
    });

    res.writeHead(200);
    res.end('closed');
})
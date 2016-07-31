var mcs = require('mcsjs');
var exec = require('child_process').exec;
var Promise = require('bluebird');
var fs = Promise.promisifyAll(require("fs"));
var SerialPort = require("serialport").SerialPort
var serialPort = new SerialPort("/dev/ttyS0", {
  baudrate: 57600
});

var myApp = mcs.register({
 deviceId: 'D2TzfAmO',
 deviceKey: 'gOfbCl0q1Wer71Ed',
// host: 'api.mediatek.com', // 如果是中國 site 的人記得加這行.
});

serialPort.on("open", function () {
        receivedData ="";
        serialPort.on('data',function(data)
        {
            console.log(data.toString());
            child = exec('fswebcam -i 0 -d v4l2:/dev/video0 --no-banner -p YUYV --jpeg 95 --save /tmp/test.jpg', function (error, stdout, stderr) {
    console.log('stdout: ' + stdout);
    console.log('stderr: ' + stderr);
    if (error !== null) {
        console.log('exec error: ' + error);
    }
    fs.readFileAsync('/tmp/test.jpg')
    .then(function(data) {
        myApp.emit('camera','', new Buffer(data).toString('base64'));
    });
});




        });
});

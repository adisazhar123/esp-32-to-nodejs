const SerialPort = require('serialport');
const Readline = require('@serialport/parser-readline');
const path = '/dev/ttyUSB0'; //change to connected usb port
const port = new SerialPort(path, { baudRate: 115200 }); //change baudrate if neccessary

const parser = new Readline();
port.pipe(parser);

module.exports = {
  init: function() {
    port.write('Hello from node');
  },
  getSerialData: function() {
    parser.on('data', line => console.log(JSON.stringify(`> ${line}`)));
  },
};

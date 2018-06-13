const Discord = require('discord.js');
const five = require('johnny-five');
const auth = require('./auth.json');

const client = new Discord.Client();
const board = new five.Board();

client.on('ready',function(){
    console.log('Im ready!');
});

board.on('ready', function(){
    var redLed = new five.Led(4);
    var greenLed = new five.Led(5);
    var blueLed = new five.Led(6);
    redLed.off();
    greenLed.off();
    blueLed.off();
    client.on('message', function(message){
        if(message.content[0]=='!'){
            switch(message.content){
                case '!red':
                    blueLed.off();
                    greenLed.off();
                    redLed.on();
                    break;
                case '!green':
                    redLed.off();
                    blueLed.off();
                    greenLed.on();
                    break;
                case '!blue':
                    greenLed.off();
                    redLed.off();
                    blueLed.on();
                    break;
                case '!off':
                    redLed.off();
                    greenLed.off();
                    blueLed.off();
                default:
                    redLed.off();
                    greenLed.off();
                    blueLed.off();
            }
        }
    });
});


client.login(auth.token);
#!/usr/bin/node

const request = require('request');
const { argv } = require('process');

const url = `https://swapi-api.hbtn.io/api/films/${argv[2]}/`;

request(url, (err, response, body) => {
  if (err) return;

  const datafilm = JSON.parse(body);

  const characters = datafilm.characters;

  function printCharacter (i) {
    if (i >= characters.length) return;

    request(characters[i], (err, res, body) => {
      if (err) return;

      const data = JSON.parse(body);
      console.log(data.name);

      printCharacter(i + 1);
    });
  }

  printCharacter(0);
});

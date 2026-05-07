#!/usr/bin/node
const request = require('request');
 
const movieId = process.argv[2];
const url = 'https://swapi-api.hbtn.io/api/films/' + movieId + '/';
 
request(url, function (error, response, body) {
  if (error) {
    console.error(error);
    return;
  }
  const film = JSON.parse(body);
  const characters = film.characters;
 
  function getCharacter (index) {
    if (index >= characters.length) return;
    request(characters[index], function (err, res, charBody) {
      if (err) {
        console.error(err);
        return;
      }
      const character = JSON.parse(charBody);
      console.log(character.name);
      getCharacter(index + 1);
    });
  }
 
  getCharacter(0);
});

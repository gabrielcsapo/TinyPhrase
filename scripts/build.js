const fs = require("fs");
const path = require("path");

const promptDir = path.resolve(__dirname, "..", "prompts");

const promptFiles = fs.readdirSync(promptDir);

let menuOptionsTxt = ["const MenuOption MenuOptions[] {"];

let largestOptionsParsed = 0;
let largestOptionsParsedPromptName = '';
let largestOptionLength = 0;
let optionsParsed = 0;

promptFiles.forEach((promptFile, index) => {
  const content = fs.readFileSync(path.resolve(promptDir, promptFile), "utf8");
  const listOfOptions = content
    .split("\n")
    .map((option) => {
      if(largestOptionLength < option.length) {
        largestOptionLength = option.length;
      }
      return option.replace(new RegExp('"', "g"), "'").replace(new RegExp("'", "g"), "\'")
    });
  if(largestOptionsParsed < listOfOptions.length) {
    largestOptionsParsed = listOfOptions.length;
    largestOptionsParsedPromptName = promptFile.replace('.txt', '');
  }
  optionsParsed += listOfOptions.length;
  menuOptionsTxt.push(`\t{${index}, "${promptFile.replace(".txt", "")}", {${listOfOptions
    .map((option) => `"${option}"`)
    .join(",")}}},`);
});

menuOptionsTxt.push("};");

console.log(menuOptionsTxt.join('\n'));

console.log('-----------------------------');
console.log('options parsed: ', optionsParsed);
console.log('menu with them most options', largestOptionsParsed, ' :: ', largestOptionsParsedPromptName)
console.log('largest option name is', largestOptionLength);
console.log('byte size: ', Buffer.byteLength(menuOptionsTxt.join('\n'), "utf-8"));
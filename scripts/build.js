const fs = require("fs");
const path = require("path");

const promptDir = path.resolve(__dirname, "..", "prompts");

const promptFiles = fs.readdirSync(promptDir);

let menuOptionsTxt = ["const MenuOption MenuOptions[] {"];

let optionsParsed = 0;

promptFiles.forEach((promptFile, index) => {
  const content = fs.readFileSync(path.resolve(promptDir, promptFile), "utf8");
  const listOfOptions = content
    .split("\n");
  optionsParsed += listOfOptions.length;
  menuOptionsTxt.push(`\t{${index}, "${promptFile.replace(".txt", "")}", {${listOfOptions
    .map((option) => `"${option}"`)
    .join(",")}}}`);
});

menuOptionsTxt.push("};");

console.log(menuOptionsTxt.join('\n'));

console.log('-----------------------------');
console.log('options parsed: ', optionsParsed);
console.log('byte size: ', Buffer.byteLength(menuOptionsTxt.join('\n'), "utf-8"));
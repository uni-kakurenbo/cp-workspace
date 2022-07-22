"use strict";

require("dotenv").config();

const fs = require("fs");
const path = require("path");

const { Client } = require("./AtCoder-Helper/APIWrapper/src");
const client = new Client();

const contestId = process.argv[2];
const problemId = process.argv[3];
const directory = process.argv[4];

console.setColor = function (...args) {
  return console;
};
console.log = function (...args) {
  return console;
};

(async function () {
  fs.promises.writeFile(path.join(__dirname, "./.log"), "test");
  let contest, problem;
  try {
    contest = await client.contests.fetch(contestId);
    problem = await contest.problems.fetch(problemId);
  } catch (e) {
    await client.login();
    contest = await client.contests.fetch(contestId);
    problem = await contest.problems.fetch(problemId, { force: true });
  }
  await problem.samples.fetchAll();
  await Promise.all(
    problem.samples.cache.map((_case, _index) => {
      return Promise.all([
        fs.promises.writeFile(path.join(directory, `${_index}.in`), _case.in),
        fs.promises.writeFile(path.join(directory, `${_index}.out`), _case.out),
      ]);
    })
  );
  process.stdout.write(String(problem.samples.cache.size));
})().catch((e) => {
  fs.promises.writeFile(path.join(__dirname, "./.log"), e.stack);
  process.stdout.write(String(0));
});

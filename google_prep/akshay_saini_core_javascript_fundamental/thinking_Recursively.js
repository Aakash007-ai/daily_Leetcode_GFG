let magic = function (obj, pre = "") {
  for (let key in obj) {
    if (typeof obj[key] === "object") {
      magic(obj[key], prev + "_" + key);
    } else {
      finalObject[prev + "_" + key] = obj[key];
    }
  }
};

let obje = {
  hello: "John",
  wick: {
    chapter: 3,
    ballerina: {
      actor: {
        hero: "Keanew",
      },
    },
  },
};

magic(obje);

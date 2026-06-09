/**
 * @param {string} senate
 * @return {string}
 */
var predictPartyVictory = function(senate) {
    let n = senate.length;

    let radiant = [];
    let dire = [];

    for (let i = 0; i < n; i++) {
        if (senate[i] === 'R') {
            radiant.push(i);
        } else {
            dire.push(i);
        }
    }

    while (radiant.length && dire.length) {
        let r = radiant.shift();
        let d = dire.shift();

        if (r < d) {
            radiant.push(r + n);
        } else {
            dire.push(d + n);
        }
    }

    return radiant.length ? "Radiant" : "Dire";
};
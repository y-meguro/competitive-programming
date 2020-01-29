
  // q.push(P(0, 0));
  // while (!q.empty()) {
  //   P p = q.front();
  //   q.pop();

  //   int u = p.first;
  //   int v = p.second;

  //   if (u >= H || v >= W) continue;

  //   if (reached.at(u).at(v)) continue;
  //   reached.at(u).at(v) = true;

  //   if (G.at(u).at(v) == '#') continue;

  //   if (u == 0 && v == 0) {
  //     dp.at(u).at(v) = 1;
  //   } else if (u == 0) {
  //     dp.at(u).at(v) = dp.at(u).at(v - 1) % mod;
  //   } else if (v == 0) {
  //     dp.at(u).at(v) = dp.at(u - 1).at(v) % mod;
  //   } else {
  //     dp.at(u).at(v) = (dp.at(u - 1).at(v) + dp.at(u).at(v - 1)) % mod;
  //   }

  //   q.push(P(u + 1, v));
  //   q.push(P(u, v + 1));
  // }
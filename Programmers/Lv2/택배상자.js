function solution(order) {
  let ans = 0;
  let sub = [];

  const order_length = order.length;
  let order_idx = 0;

  for(let i=1; i<=order_length; i++) {
    if(i === order[order_idx]) {
      order_idx++;
      ans++;
    } else {
      sub.push(i);
    }

    while(sub && sub.length) {
      if(sub.at(-1) === order[order_idx]) {
        order_idx++;
        sub.pop();
        ans++;
      } else {
        break;
      }
    }
  }
  return ans;
}
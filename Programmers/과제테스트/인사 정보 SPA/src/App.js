class App {
  constructor($body) {
    this.$body = $body;
    this.render();
  }

  render() {
    const a = document.createElement('div');
    a.innerHTML = 'test';
    this.$body.appendChild(a);
  }
}

export default App;

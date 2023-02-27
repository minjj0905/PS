class Header {
  constructor($body) {
    this.$body = $body;
  }

  createMenuElem(divC, spanC, spanI, text) {
    const div = document.createElement('div');
    div.setAttribute('class', divC);

    const span = document.createElement('span');
    span.setAttribute('class', spanC);
    span.setAttribute('id', spanI);
    span.appendChild(document.createTextNode(text));

    div.appendChild(span);
    return div;
  }

  render() {
    const header = document.createElement('header');

    header.appendChild(this.createMenuElem('header header_left', 'menu_name', 'menu_home', 'HOME'));
    header.appendChild(
      this.createMenuElem('header header_right', 'menu_name', 'menu_signup', 'SIGNUP'),
    );

    this.$body.appendChild(header);
  }
}

export default Header;

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

    const home_menu = this.createMenuElem('header header_left', 'menu_name', 'menu_home', 'HOME');
    const signup_menu = this.createMenuElem(
      'header header_right',
      'menu_name',
      'menu_signup',
      'SIGNUP',
    );
    header.appendChild(home_menu);
    header.appendChild(signup_menu);
    this.$body.appendChild(header);

    home_menu.addEventListener('click', () => {
      window.history.pushState('', '', '/web/');
      const urlChange = new CustomEvent('urlchange', {
        detail: { href: '/web/' },
      });
      document.dispatchEvent(urlChange);
    });

    signup_menu.addEventListener('click', () => {
      window.history.pushState('', '', '/web/signup');
      const urlChange = new CustomEvent('urlchange', {
        detail: { href: '/web/signup' },
      });
      document.dispatchEvent(urlChange);
    });
  }
}

export default Header;

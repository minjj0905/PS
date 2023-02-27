import Header from './components/Header.js';
import HomePage from './page/HomePage.js';
import SignupPage from './page/SignupPage.js';

class App {
  constructor($body) {
    this.$body = $body;
    this.render();
  }

  render() {
    const header = new Header(this.$body);
    header.render();

    const main = document.createElement('main');
    main.setAttribute('id', 'page_content');
    this.$body.appendChild(main);

    const homePage = new HomePage(main);
    const signupPage = new SignupPage(main);

    document.addEventListener('urlchange', (e) => {
      let pathname = e.detail.href;
      console.log(pathname);

      switch (pathname) {
        case '/web/':
          homePage.render();
          break;
        case '/web/signup':
          signupPage.render();
          break;
        default:
          break;
      }
    });
  }
}

export default App;

import React from 'react';
import ReactDOM from 'react-dom';

function Welcome() {
    return React.createElement(
        "h1",
        null,
        "Olá Mundo!"
    );
}

ReactDOM.render(
    React.createElement(Welcome),
    document.getElementById('root')
);

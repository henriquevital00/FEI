/**
 * @class       : Botao
 * @author      : Henrique Vital Carvalho (henriquevital1000@hotmail.com)
 * @created     : sábado out 24, 2020 16:59:50 -03
 * @description : Botao
 */

import React, {Component} from 'react';

class Botao extends Component {
    render(){
        return(
            <input
                style = {{backgroundColor : "blue",
                    width:40, fontSize:"18pt"}}
                    type = "button"
                    value={this.props.children}
                    onClick={this.props.clique}>
            </input>
        );
    }
}

export default Botao;


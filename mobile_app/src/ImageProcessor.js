import React, { Component } from 'react';
import {
    View,
    Text,
    TextInput,
    Image,
    Button,
    AppRegistry
} from 'react-native';

import Style from './Style';


class ImageProcessor extends Component {
    blur() {
        alert('Blur');
    }
    sharpen() {
        alert('Sharpened');
    }
    getImage() {
        alert('Got image');
    }

    render() {
        return (
        <View style={Style.rootContainer}>
            <Image 
                source={{uri: 'https://facebook.github.io/react/img/logo_og.png'}} 
                style={Style.imageContainer}
            />
            <View style={Style.displayContainer}>
                <View style={Style.buttonContainer}>
                    <Button
                        onPress={this.blur.bind(this)}
                        title="Blur"
                        color="steelblue"
                    />
                </View>
                <View style={Style.buttonContainer}>
                    <Button
                        onPress={this.sharpen.bind(this)}
                        title="Sharpen"
                        color="steelblue"
                    />
                </View>
            </View>
            <View style={Style.getImageContainer}>
                <TextInput
                    placeholder="Enter image id to retrieve"
                    blurOnSubmit={true} 
                    returnKeyType={"done"}
                    style={Style.textBox}
                    onSubmitEditing={this.getImage.bind(this)}
                />
            </View>
        </View>
        )
    }
}
            
AppRegistry.registerComponent('ImageProcessor',() => ImageProcessor);
   

var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');

var indexRouter = require('./routes/index');
var usersRouter = require('./routes/users');

var app = express();

// declaration du module Mongoose
var mongoose = require('mongoose');


app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);
app.use('/users', usersRouter);

//Déclaration de la librairie nécessaire pour l'initialisation avec le serveur
var passport = require('passport');

//Déclaration des variables pour les routes Authentication, Category et Post
var auth = require('./routes/auth');
var category = require('./routes/category');
var post = require('./routes/post');

//Initialisation du passport
app.use(passport.initialize());

//Ajout des API Route à l'URL du point de terminaison
app.use('/api/auth', auth);
app.use('/api/category', category);
app.use('/api/post', post);

module.exports = app;

//Creation de la connection à MongoDB Server
mongoose.connect('mongodb://localhost/blog-cms', {
 promiseLibrary: require('bluebird'),
 useNewUrlParser: true,
 useUnifiedTopology: true,
 useCreateIndex: true
}).then(() => console.log('connection successful'))
 .catch((err) => console.error(err));

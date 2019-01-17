# Week 1 Notes

The singularity will never happen because we are not building machines that are going towards human intelligence. These machines are built for a single, super specific, task.

What is learning?

We all have some model, a mental understanding of things. Artifacts are used to augment or change that model. The artifacts are the data points that we can then learn and create a model from.

In data science we will be building a model, and we will use the data as our measured artifact to augment the model.

Definition:

> _"The field of study that gives computers the ability to learn without being explicitly programming."_ - Arthur Samuel, famous for programming a computer to play checkers. The first use of machine learning.

Why ML and Why now?

* progress in algorithms and computational power
* flood of data
* problems are matched by algorithms and data and power. We now have all three.

Applications at a glance

* SW engineering data driven
* Data mining
	* historical data to improve predictions
	* classifies medical images -> new images -> new predictions
* SW engineering
	* cannot encode all cases as if/then/else
	* NLP, speech processing, autonomous systems, self driving cars
* continuous performance improvement based on new data
	* more data, better predictions
	* summarizers

Symbolic vs. continuous data

symbolic: not changing, clearly defined
continuous: rule based systems, a picture, EEG

tasks

* classifications - Yes or no, is this a cat. Classifying pictures
* clustering - Grouping, similar to classification.
* regressions - Identifying trends in a data set. Stock market predictions.
* localization - Temporal position within the overall pattern, location based data. Heat maps?

types

* supervised, we know the answer to the data, finding blobs, we don't know what they are but we categorize them
* unsupervised, we do not know the answer to the data, as in we do not have labels associated to the data
* semi-supervised, hybrid approach

steps

* pre-processing
* feature extraction
* representation
* learning
* prediction


what is the essence of learning

convert data into a model, and use that model to create predictions

delta = difference between predictions and data

continue changing our model until  error gets low

feed the model new data

overfitting is useful for security

training data set = T

new data being used for validation = V

error loss = J

subscripts = parameters
